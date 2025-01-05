
set(SOURCES
    source/XmlItemCreateVisitor.cpp
    source/XmlVMCreateVisitor.cpp
    source/XmlWriter.cpp
)

set(HEADERS
    interface/xmlwriter/XmlItemCreateVisitor.h
    interface/xmlwriter/XmlVMCreateVisitor.h
    interface/xmlwriter/XmlWriter.h
) 
 
 
add_library(XmlWriter ${SOURCES} ${HEADERS})

target_include_directories(XmlWriter INTERFACE interface/xmlwriter)