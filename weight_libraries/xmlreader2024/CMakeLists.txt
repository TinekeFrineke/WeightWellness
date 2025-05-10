add_library(xmlreader2024 STATIC
    source/XmlReader.cpp
    interface/xmlreader/XmlReader.h
)

target_include_directories(xmlreader2024 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/interface/xmlreader/
    "C:/Projects/Combined/Xerces280/src/"
    "C:/Projects/Combined/utilities_versions/v1.0.2/interface/"
)

target_link_libraries(xmlreader2024 PUBLIC
    model_interface
    xmlbase_interface
    generated2024
)
