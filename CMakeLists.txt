cmake_minimum_required(VERSION 3.25)

project(Noise_Generator 
        VERSION 0.0.1 
        LANGUAGES CXX)

option(UNICODE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE 
    "${PROJECT_SOURCE_DIR}/src/NoiseGeneratorApp.cpp"
    "${PROJECT_SOURCE_DIR}/src/Window.cpp")

add_executable(Noise_Generator WIN32 ${SOURCE} ${HEADERS})

target_include_directories(Noise_Generator PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src")

configure_file("${PROJECT_SOURCE_DIR}/src/NoiseGeneratorAppConfig.h.in" 
               "${PROJECT_SOURCE_DIR}/src/NoiseGeneratorAppConfig.h")