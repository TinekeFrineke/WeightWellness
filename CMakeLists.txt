cmake_minimum_required(VERSION 3.16)

set_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

project(WeightWellness VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

add_compile_definitions(_UNICODE UNICODE)
add_compile_options(/permissive- /GS /W3 /Zc:wchar_t /sdl /Zc:inline /fp:precise /errorReport:prompt /WX /Zc:forScope /FC /EHsc /nologo /diagnostics:column)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG /Od /ZI /RTC2 /MDd)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(NDEBUG /O2 /RTC0 /MD)
endif()

add_subdirectory(Generated2024)
add_subdirectory(Model)
add_subdirectory(QmlResource)
add_subdirectory(ViewModel)
add_subdirectory(WeightControl)
add_subdirectory(XmlBase)
add_subdirectory(XmlReader2024)
add_subdirectory(XmlWriter2024)

