
set(SOURCES
    source/XmlReader.cpp
)

set(HEADERS
    interface/xmlreader/XmlReader.h
) 
 
 
add_library(XmlReader ${SOURCES} ${HEADERS})

target_include_directories(XmlReader INTERFACE interface/xmlreader)