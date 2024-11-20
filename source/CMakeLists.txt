# Declare library

find_package(SFML REQUIRED)

add_library(snake_lib)

target_link_libraries(snake_lib PUBLIC sfml::sfml)

target_sources(snake_lib
    PUBLIC
        "${PROJECT_SOURCE_DIR}/includes/constants/Constants.hpp"
        "${PROJECT_SOURCE_DIR}/includes/fruit/Fruit.hpp"
        "${PROJECT_SOURCE_DIR}/includes/fruit/Fruit.cpp"
        "${PROJECT_SOURCE_DIR}/includes/game/Game.hpp"
        "${PROJECT_SOURCE_DIR}/includes/game/Game.cpp"
        "${PROJECT_SOURCE_DIR}/includes/snake/Snake.hpp"
        "${PROJECT_SOURCE_DIR}/includes/snake/Snake.cpp"
)

target_include_directories(snake_lib
    PUBLIC
        "${PROJECT_SOURCE_DIR}/includes/constants/"
        "${PROJECT_SOURCE_DIR}/includes/fruit/"
        "${PROJECT_SOURCE_DIR}/includes/fruit/"
        "${PROJECT_SOURCE_DIR}/includes/game/"
        "${PROJECT_SOURCE_DIR}/includes/game/"
        "${PROJECT_SOURCE_DIR}/includes/snake/"
        "${PROJECT_SOURCE_DIR}/includes/snake/"
)

target_compile_features(snake_lib PUBLIC cxx_std_20)

# Declare executable

add_executable(snake_exe)
target_sources(snake_exe
    PRIVATE
        main.cpp
)

add_executable(snake::exe ALIAS snake_exe)

set_property(TARGET snake_exe PROPERTY OUTPUT_NAME snake)

target_compile_features(snake_exe PRIVATE cxx_std_20)

target_compile_options(snake_exe
    PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Werror -Wpedantic>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)

target_link_libraries(snake_exe PRIVATE snake_lib)
