# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
    
    set(
        CMAKE_BUILD_TYPE RelWithDebInfo 
        CACHE STRING "Choose the type of build." FORCE
    )

    # Set the possible values of build type for cmake-gui and ccmake
    set_property(
        CACHE CMAKE_BUILD_TYPE PROPERTY 
        STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo"
    )

endif(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enhance error-reporting and compiler messages
if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    if(WIN32)
        # On Windows Cuda nvcc uses cl and not Clang
        add_compile_options($<$<COMPILE_LANGUAGE:C>:-fcolor-diagnostics> $<$<COMPILE_LANGUAGE:CXX>:-fcolor-diagnostics>)
    else()
        add_compile_options(-fcolor-diagnostics)
    endif(WIN32)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(WIN32)
        # On Windows Cuda nvcc uses cl and not GCC
        add_compile_options($<$<COMPILE_LANGUAGE:C>:-fdiagnostics-color=always> $<$<COMPILE_LANGUAGE:CXX>:-fdiagnostics-color=always>)
    else()
        add_compile_options(-fdiagnostics-color=always)
    endif(WIN32)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" AND MSVC_VERSION GREATER 1900)
    add_compile_options(/diagnostics:column)

else()
    message(STATUS "No colored compiler diagnostic set for '${CMAKE_CXX_COMPILER_ID}' compiler.")

endif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")

