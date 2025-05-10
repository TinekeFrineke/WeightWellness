
add_library(xmlbase_interface INTERFACE
    interface/xmlbase/XmlBase.h
)


target_include_directories(xmlbase_interface INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)
