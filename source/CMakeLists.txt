# Declare executable

find_package(SFML REQUIRED)

add_executable(snake_exe)
target_sources(snake_exe
    PRIVATE
        main.cpp
        Constants.hpp
        Fruit.hpp
        Fruit.cpp
)

add_executable(snake::exe ALIAS snake_exe)

set_property(TARGET snake_exe PROPERTY OUTPUT_NAME snake)

target_compile_features(snake_exe PRIVATE cxx_std_20)

target_compile_options(snake_exe
    PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Werror -Wpedantic>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

target_link_libraries(snake_exe PRIVATE sfml::sfml)
