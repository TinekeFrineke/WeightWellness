cmake_minimum_required(VERSION 3.16)
project(model LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Prepare a .cmake file for repetitious heavy lifting
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cmake/SetOutputDirectories.cmake)

if(CMAKE_SIZEOF_VOID_P EQUAL 8) # x64
    set(CMAKE_GENERATOR_TOOLSET "v143")  # Replace with your toolset version if different
    set(TOOL_DIR "vs2022")
    set(ARCH_DIR "x64")
else()
    set(CMAKE_GENERATOR_TOOLSET "v142")  # Replace with your toolset version if different
    set(TOOL_DIR "vs2019")
    set(ARCH_DIR "Win32")
endif()

# Set output directories relative to root, by configuration
set(OUTPUT_BASE ${CMAKE_SOURCE_DIR}/build/${TOOL_DIR}/${CMAKE_BUILD_TYPE}/${ARCH_DIR}})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE}) # for .lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE}) # for .dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE}) # for .exe

add_subdirectory(model)
add_subdirectory(generated2024)
add_subdirectory(xmlbase)
add_subdirectory(xmlreader2024)
add_subdirectory(xmlwriter2024)
