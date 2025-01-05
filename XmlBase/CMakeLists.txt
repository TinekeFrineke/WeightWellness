
set(HEADERS
    interface/xmlbase/XmlBase.h
) 
 
 
add_library(XmlBase INTERFACE ${HEADERS})

target_include_directories(XmlBase INTERFACE interface/xmlbase)