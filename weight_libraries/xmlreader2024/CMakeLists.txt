
add_library(xmlreader2024 STATIC
    source/XmlReader.cpp
    interface/xmlreader/XmlReader.h
)


set_output_directories(xmlreader2024)

target_include_directories(xmlreader2024 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/interface/xmlreader/
    "C:/Projects/Combined/Xerces280/src/"
    "C:/Projects/Combined/utilities_versions/v1.0.2/interface/"
)

target_compile_definitions(xmlreader2024 PRIVATE
    PROJ_XMLUTIL
    PROJ_XMLPARSER
    PROJ_SAX4C
    PROJ_SAX2
    PROJ_PARSERS
    PROJ_DOM
    PROJ_VALIDATORS
    PROJ_FRAMEWORK
)

target_link_libraries(xmlreader2024 PUBLIC
    model_interface
    xmlbase_interface
    generated2024
)
