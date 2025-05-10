cmake_minimum_required(VERSION 3.16)
project(model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

if(CMAKE_SIZEOF_VOID_P EQUAL 8) # x64
set(CMAKE_GENERATOR_TOOLSET "v142")  # Replace with your toolset version if different
endif()

# Set output directories relative to root, by configuration
set(OUTPUT_BASE ${CMAKE_SOURCE_DIR}/../build/${CMAKE_GENERATOR_TOOLSET})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_PROCESSOR}) # for .lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_PROCESSOR}) # for .dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_PROCESSOR}) # for .exe

add_subdirectory(model)
add_subdirectory(generated2024)
add_subdirectory(xmlbase)
add_subdirectory(xmlreader2024)
add_subdirectory(xmlwriter2024)
