from conan import ConanFile
from conan.tools.cmake import cmake_layout

class SnakeRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("sfml/2.6.1")

