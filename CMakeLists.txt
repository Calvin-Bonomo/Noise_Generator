cmake_minimum_required(VERSION 3.25)

project(Noise_Generator 
        VERSION 0.0.1 
        LANGUAGES CXX)

option(UNICODE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND SOURCES
    "${PROJECT_SOURCE_DIR}/src/NoiseGeneratorApp.cpp"
    "${PROJECT_SOURCE_DIR}/src/Window.cpp")

list(APPEND HEADERS
    "${PROJECT_SOURCE_DIR}/src/Window.h")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    message("Making Debug Build...")
    list(APPEND SOURCES
        "${PROJECT_SOURCE_DIR}/src/debug/DebugConsole.cpp")
    list(APPEND HEADERS
        "${PROJECT_SOURCE_DIR}/src/debug/DebugConsole.h"
        "${PROJECT_SOURCE_DIR}/src/debug/DebugTools.h")
endif()

add_executable(Noise_Generator WIN32 ${SOURCES} ${HEADERS})

list(APPEND INCLUDE_DIRS
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_definitions(DEBUG)
    list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src/debug")
endif()

target_include_directories(Noise_Generator PUBLIC 
                          ${INCLUDE_DIRS})

configure_file("${PROJECT_SOURCE_DIR}/src/NoiseGeneratorAppConfig.h.in" 
               "${PROJECT_SOURCE_DIR}/src/NoiseGeneratorAppConfig.h")