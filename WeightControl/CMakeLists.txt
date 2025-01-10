
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/msvc2022_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) # Enables automatic resource handling

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Quick Widgets)

qt_policy(SET QTP0001 NEW)

set(SOURCES
    source/WeightControl.cpp
)

set(HEADERS
    header/WeightControl.h
) 
 
 
add_executable(WeightControl ${SOURCES} ${HEADERS})

target_include_directories(WeightControl PUBLIC
    header
    C:/Projects/VC2022/Utilities/include
    C:/Projects/VC2022/xerces280/src
    ${CMAKE_SOURCE_DIR}/Model/interface
    ${CMAKE_SOURCE_DIR}/XmlReader2024/interface
    ${CMAKE_SOURCE_DIR}/XmlWriter2024/interface
)

message(STATUS "CMAKE_BINARY_DIR  == ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_BUILD_TYPE  == ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_GENERATOR_PLATFORM  == ${CMAKE_GENERATOR_PLATFORM}")

if(CMAKE_CONFIGURATION_TYPES)
    foreach(config ${CMAKE_CONFIGURATION_TYPES})
        if(config STREQUAL "Debug")
            message(STATUS "Debug configuration is defined")
        elseif(config STREQUAL "Release")
            message(STATUS "Release configuration is defined")
        endif()
    endforeach()
else()
    message(STATUS "CMAKE_CONFIGURATION_TYPES is not set (single-configuration generator?)")
endif()


# Set the output directories for different configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM}/Release)

# Link the library and Qt modules to the console app
target_link_libraries(WeightControl PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Widgets
    Generated2024
    Model
    QmlResourceLibplugin
    XmlReader
    XmlWriter
    $<$<CONFIG:Debug>:C:/Projects/VC2019/xerces280/Build/Win64/VC2019/Debug/xerces-c_2_8D.lib>
    $<$<CONFIG:Release>:C:/Projects/VC2019/xerces280/Build/Win64/VC2019/Release/xerces-c_2_8.lib>
    $<$<CONFIG:Debug>:C:/Projects/VC2022/Utilities/x64/Debug/Utilities.lib>
    $<$<CONFIG:Release>:C:/Projects/VC2022/Utilities/x64/Release/Utilities.lib>
)

source_group(weightcontrol)