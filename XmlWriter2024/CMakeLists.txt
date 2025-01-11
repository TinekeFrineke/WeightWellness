
set(SOURCES
    source/XmlItemCreateVisitor.cpp
    source/XmlVMCreateVisitor.cpp
    source/XmlWriter.cpp
)

set(HEADERS
    header/XmlItemCreateVisitor.h
    header/XmlVMCreateVisitor.h
    interface/xmlwriter/XmlWriter.h
) 
 
add_library(XmlWriter ${SOURCES} ${HEADERS})

target_include_directories(XmlWriter PUBLIC
    interface/xmlwriter
    ${CMAKE_SOURCE_DIR}/XmlBase/interface
)

target_include_directories(XmlWriter PRIVATE
    header
    C:/Projects/VC2022/Utilities/include
    C:/Projects/VC2022/xerces280/src
    ${CMAKE_SOURCE_DIR}/Generated2024/interface
    ${CMAKE_SOURCE_DIR}/Model/interface
)

target_link_libraries(XmlWriter XmlBase)

set_target_properties(XmlWriter PROPERTIES FOLDER WeightControl)
