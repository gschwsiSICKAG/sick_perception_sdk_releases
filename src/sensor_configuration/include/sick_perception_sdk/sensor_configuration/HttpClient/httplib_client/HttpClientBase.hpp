/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>

#define CPPHTTPLIB_OPENSSL_SUPPORT 1
#include <httplib.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>

namespace sick::httplib_client {

namespace {

void throwIfNotSuccessful(httplib::Result const& result, std::string const& method, std::string const& endpoint)
{
  if (!result)
  {
    switch (result.error())
    {
    case httplib::Error::SSLConnection:
      throw std::runtime_error("HTTP " + method + " " + endpoint + " failed due to SSL connection error: " + std::to_string(result.ssl_error()));
      break;
    case httplib::Error::SSLLoadingCerts:
      throw std::runtime_error("HTTP " + method + " " + endpoint + " failed due to SSL cert loading error: " + std::to_string(result.ssl_openssl_error()));
      break;
    case httplib::Error::SSLServerVerification:
      throw std::runtime_error("HTTP " + method + " " + endpoint + " failed due to SSL verification error: " + std::to_string(result.ssl_openssl_error()));
      break;
    case httplib::Error::SSLServerHostnameVerification:
      throw std::runtime_error(
        "HTTP " + method + " " + endpoint + " failed due to SSL hostname verification, X509 error: " + std::to_string(result.ssl_openssl_error())
      );
      break;
    default:
      throw std::runtime_error("HTTP " + method + " " + endpoint + " failed: " + httplib::to_string(result.error()));
    }
  }
}

} // namespace

/**
 * @brief Base class for HTTP clients using [httplib](https://github.com/yhirose/cpp-httplib).
 */
template <class ClientT>
class HttpClientBase : public IHttpClient
{
public:
  template <typename... Args>
  explicit HttpClientBase(Args&&... args)
    : m_client(std::make_unique<ClientT>(std::forward<Args>(args)...))
  {
    auto const startTime = std::chrono::steady_clock::now();
    m_client->set_logger([startTime](httplib::Request const& req, httplib::Response const& res) {
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count();
      LOG_FAST_LOOP_INFO("HttpClient") << "OK: " << req.method << " " << req.path << " -> " << res.status << " (" << res.body.size() << " bytes, " << duration
                                       << "ms)";
    });

    m_client->set_error_logger([](httplib::Error const& err, httplib::Request const* req) -> void {
      std::string message = "Request ";
      if (req)
      {
        message += req->method + " " + req->path + " ";
      }
      message += "failed: " + httplib::to_string(err);
      LOG_ERROR("HttpClient") << message;
    });
  }

  virtual ~HttpClientBase() = default;

  auto get(std::string const& endpoint) const -> std::string
  {
    auto const result = m_client->Get(endpoint);
    throwIfNotSuccessful(result, "GET", endpoint);
    return result->body;
  }

  auto post(std::string const& endpoint, std::string const& payload) const -> std::string
  {
    auto const result = m_client->Post(endpoint, payload, "application/json");
    throwIfNotSuccessful(result, "POST", endpoint);
    return result->body;
  }

  /**
   * @brief Provide raw access to the underlying httplib client.
   * 
   * This is useful for advanced configurations or operations not covered by this wrapper.
   * See the [httplib documentation](https://github.com/yhirose/cpp-httplib) options and details.
   */
  auto client() const -> ClientT&
  {
    return *m_client;
  }

protected:
  std::unique_ptr<ClientT> m_client;
};

} // namespace sick::httplib_client
