
set(SOURCES
    source/XmlReader.cpp
)

set(HEADERS
    interface/xmlreader/XmlReader.h
) 
 
 
add_library(XmlReader ${SOURCES} ${HEADERS})

target_include_directories(XmlReader PUBLIC
    interface/xmlreader
    ${CMAKE_SOURCE_DIR}/XmlBase/interface
)

target_include_directories(XmlReader PRIVATE
    C:/Projects/VC2022/Utilities/include
    C:/Projects/VC2022/xerces280/src
    ${CMAKE_SOURCE_DIR}/Generated2024/interface
    ${CMAKE_SOURCE_DIR}/Model/interface
)

target_link_libraries(XmlReader XmlBase)

set_target_properties(XmlReader PROPERTIES FOLDER WeightControl)
