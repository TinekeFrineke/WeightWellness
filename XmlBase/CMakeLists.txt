
set(HEADERS
    interface/xmlbase/XmlBase.h
) 
 
 
add_library(XmlBase INTERFACE ${HEADERS})

target_include_directories(XmlBase INTERFACE interface/xmlbase)

message(STATUS "Setting folder for XmlBase to QmlResource")
set_target_properties(XmlBase PROPERTIES FOLDER WeightControl)
