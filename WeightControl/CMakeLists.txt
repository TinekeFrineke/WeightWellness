
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

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(XERCESLIB xerces-c_2_8D)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)  # 64-bit
        target_link_directories(WeightControl PRIVATE
            C:/Projects/VC2022/Utilities/x64/Debug
            C:/Projects/VC2019/xerces280/Build/Win64/VC2019/Debug
        )
    else ()  # 32-bit
        target_link_directories(WeightControl PRIVATE
            C:/Projects/VC2022/Utilities/Win32/Debug
            C:/Projects/VC2019/xerces280/Build/Win32/VC2019/Debug
        )
    endif ()
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(XERCESLIB xerces-c_2_8)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)  # 64-bit
        target_link_directories(WeightControl PRIVATE
            C:/Projects/VC2022/Utilities/x64/Release
            C:/Projects/VC2019/xerces280/Build/Win64/VC2019/Release
        )
    else ()  # 32-bit
        target_link_directories(WeightControl PRIVATE 
            C:/Projects/VC2022/Utilities/Win32/Release
            C:/Projects/VC2019/xerces280/Build/Win32/VC2019/Release
        )
    endif ()
endif ()

# Set the output directories for different configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM}/Release)

# Link the library and Qt modules to the console app
target_link_libraries(WeightControl PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Widgets
    #QmlResourceLibplugin
    ${XERCESLIB}
    Utilities
    Generated2024
    Model
    QmlResourceLibplugin
    XmlReader
    XmlWriter
)
