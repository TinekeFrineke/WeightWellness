add_library(xmlwriter2024 STATIC
    source/XmlItemCreateVisitor.cpp
    source/XmlVMCreateVisitor.cpp
    source/XmlWriter.cpp
    interface/xmlwriter/XmlItemCreateVisitor.h
    interface/xmlwriter/XmlVMCreateVisitor.h
    interface/xmlwriter/XmlWriter.h
)


target_include_directories(xmlwriter2024 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/interface/xmlwriter/
    "C:/Projects/Combined/Xerces280/src/"
)

target_link_libraries(xmlwriter2024 PRIVATE
    xmlbase_interface
    model_interface
    generated2024
)