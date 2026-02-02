from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout, CMakeDeps

required_conan_version = ">=2.13"


class SickPerceptionSDK(ConanFile):
    name = "sick_perception_sdk"
    version = "0.0.0"
    url = "https://gitlab.sickcn.net/GBC08/development/tools/digitalaccessories/lidar-sdk/sick-sensor-sdk.git"
    description = "This packages contains SDK components for interacting with SICK sensors."
    license = "Copyright SICK AG"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "cmake/*", "src/*", "LICENSE", "README.md"

    options = {
        "shared": [True, False],
        "build_drivers": [True, False],
        "build_compact_receiver": [True, False],
        "build_sensor_configuration": [True, False],
        "build_unit_tests": [True, False],
        "build_examples": [True, False],
    }

    default_options = {
        "shared": False,
        "build_drivers": True,
        "build_compact_receiver": True,
        "build_sensor_configuration": True,
        "build_unit_tests": False,
        "build_examples": False,
    }

    def configure(self):
        if self.options.get_safe("shared"):
            del self.options.fPIC

        # Configure OpenSSL linking strategy:
        # - Dynamic runtime (/MD) requires shared OpenSSL to avoid runtime library conflicts
        # - Shared SDK build uses shared OpenSSL
        # - Static SDK build with static runtime (/MT) uses static OpenSSL
        if self.settings.compiler == "msvc" and self.settings.compiler.runtime == "dynamic":
            self.options["openssl"].shared = True
        elif self.options.get_safe("shared"):
            self.options["openssl"].shared = True
        else:
            self.options["openssl"].shared = False

        # Match gtest runtime to compiler settings when building unit tests
        if self.options.build_unit_tests:
            if self.settings.compiler == "msvc" and self.settings.compiler.runtime == "dynamic":
                self.options["gtest"].shared = True

    def requirements(self):
        self.requires("plog/1.1.10")
        if self.options.get_safe("build_sensor_configuration") or self.options.get_safe("build_drivers") or self.options.get_safe("build_examples"):
            self.requires("cpp-httplib/0.27.0", transitive_headers=True)
            self.requires("nlohmann_json/3.11.3", transitive_headers=True)
            self.requires("openssl/3.4.1", transitive_headers=True)
        if self.options.get_safe("build_compact_receiver") or self.options.get_safe("build_drivers") or self.options.get_safe("build_examples"):
            self.requires("zlib/1.3.1")
        if self.options.get_safe("build_unit_tests"):
            self.requires("gtest/1.14.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["BUILD_SHARED_LIBS"] = self.options.shared
        tc.variables["BUILD_DRIVERS"] = self.options.build_drivers
        tc.variables["BUILD_COMPACT_RECEIVER"] = self.options.build_compact_receiver
        tc.variables["BUILD_SENSOR_CONFIGURATION"] = self.options.build_sensor_configuration
        tc.variables["BUILD_UNIT_TESTS"] = self.options.build_unit_tests
        tc.variables["BUILD_EXAMPLES"] = self.options.build_examples
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(
            variables={
                "BUILD_SHARED_LIBS": self.options.shared,
                "BUILD_DRIVERS": self.options.build_drivers,
                "BUILD_COMPACT_RECEIVER": self.options.build_compact_receiver,
                "BUILD_SENSOR_CONFIGURATION": self.options.build_sensor_configuration,
                "BUILD_UNIT_TESTS": self.options.build_unit_tests,
                "BUILD_EXAMPLES": self.options.build_examples,
            }
        )
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # Set the CMake config file location
        self.cpp_info.set_property("cmake_file_name", "sick_perception_sdk")

        # Define the common component (always required)
        self.cpp_info.components["common"].libs = ["common"]
        self.cpp_info.components["common"].set_property("cmake_target_name", "sick_perception_sdk::common")
        self.cpp_info.components["common"].requires = ["plog::plog"]

        # Define library components based on what was built
        if self.options.get_safe("build_drivers"):
            self.cpp_info.components["drivers"].libs = ["drivers"]
            self.cpp_info.components["drivers"].set_property("cmake_target_name", "sick_perception_sdk::drivers")
            self.cpp_info.components["drivers"].requires = ["common", "compact_receiver", "sensor_configuration", "cpp-httplib::cpp-httplib", "nlohmann_json::nlohmann_json", "openssl::openssl"]
            self.cpp_info.components["drivers"].requires.append("zlib::zlib")

        if self.options.get_safe("build_compact_receiver"):
            self.cpp_info.components["compact_receiver"].libs = ["compact_receiver"]
            self.cpp_info.components["compact_receiver"].set_property("cmake_target_name", "sick_perception_sdk::compact_receiver")
            self.cpp_info.components["compact_receiver"].requires = ["common", "zlib::zlib"]

        if self.options.get_safe("build_sensor_configuration"):
            self.cpp_info.components["sensor_configuration"].libs = ["sensor_configuration"]
            self.cpp_info.components["sensor_configuration"].set_property("cmake_target_name", "sick_perception_sdk::sensor_configuration")
            self.cpp_info.components["sensor_configuration"].requires = ["common", "cpp-httplib::cpp-httplib", "nlohmann_json::nlohmann_json", "openssl::openssl"]
