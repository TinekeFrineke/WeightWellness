
set(SOURCES
    source/XmlBonuscell.cpp
    source/XmlBonuscellReader.cpp
    source/XmlBonuscellWriter.cpp
    source/XmlBonuslist.cpp
    source/XmlBonuslistReader.cpp
    source/XmlBonuslistWriter.cpp
    source/XmlClass.cpp
    source/XmlDag.cpp
    source/XmlDagReader.cpp
    source/XmlDagWriter.cpp
    source/XmlHandmatigitem.cpp
    source/XmlHandmatigitemReader.cpp
    source/XmlHandmatigitemWriter.cpp
    source/XmlPersonalia.cpp
    source/XmlPersonaliaReader.cpp
    source/XmlPersonaliaWriter.cpp
    source/XmlPortie.cpp
    source/XmlPortieReader.cpp
    source/XmlPortieWriter.cpp
    source/XmlRecept.cpp
    source/XmlReceptdef.cpp
    source/XmlReceptdefReader.cpp
    source/XmlReceptdefs.cpp
    source/XmlReceptdefsReader.cpp
    source/XmlReceptdefsWriter.cpp
    source/XmlReceptdefWriter.cpp
    source/XmlReceptReader.cpp
    source/XmlReceptWriter.cpp
    source/XmlUnit.cpp
    source/XmlUnitReader.cpp
    source/XmlUnits.cpp
    source/XmlUnitsReader.cpp
    source/XmlUnitsWriter.cpp
    source/XmlUnitWriter.cpp
    source/XmlVoedingsmiddel.cpp
    source/XmlVoedingsmiddeldef.cpp
    source/XmlVoedingsmiddeldefReader.cpp
    source/XmlVoedingsmiddeldefs.cpp
    source/XmlVoedingsmiddeldefsReader.cpp
    source/XmlVoedingsmiddeldefsWriter.cpp
    source/XmlVoedingsmiddeldefWriter.cpp
    source/XmlVoedingsmiddelReader.cpp
    source/XmlVoedingsmiddelWriter.cpp
    source/XmlVoedingswaarde.cpp
    source/XmlVoedingswaardeReader.cpp
    source/XmlVoedingswaardeWriter.cpp
    source/XmlWeek.cpp
    source/XmlWeekReader.cpp
    source/XmlWeekWriter.cpp
)

set(HEADERS
    interface/generated/XmlBonuscell.h
    interface/generated/XmlBonuscellReader.h
    interface/generated/XmlBonuscellWriter.h
    interface/generated/XmlBonuslist.h
    interface/generated/XmlBonuslistReader.h 
    interface/generated/XmlBonuslistWriter.h 
    interface/generated/XmlClass.h 
    interface/generated/XmlDag.h 
    interface/generated/XmlDagReader.h 
    interface/generated/XmlDagWriter.h 
    interface/generated/XmlHandmatigitem.h 
    interface/generated/XmlHandmatigitemReader.h 
    interface/generated/XmlHandmatigitemWriter.h 
    interface/generated/XmlPersonalia.h 
    interface/generated/XmlPersonaliaReader.h 
    interface/generated/XmlPersonaliaWriter.h 
    interface/generated/XmlPortie.h 
    interface/generated/XmlPortieReader.h 
    interface/generated/XmlPortieWriter.h 
    interface/generated/XmlRecept.h 
    interface/generated/XmlReceptdef.h 
    interface/generated/XmlReceptdefReader.h 
    interface/generated/XmlReceptdefs.h 
    interface/generated/XmlReceptdefsReader.h 
    interface/generated/XmlReceptdefsWriter.h 
    interface/generated/XmlReceptdefWriter.h 
    interface/generated/XmlReceptReader.h 
    interface/generated/XmlReceptWriter.h 
    interface/generated/XmlUnit.h 
    interface/generated/XmlUnitReader.h 
    interface/generated/XmlUnits.h 
    interface/generated/XmlUnitsReader.h 
    interface/generated/XmlUnitsWriter.h 
    interface/generated/XmlUnitWriter.h 
    interface/generated/XmlVoedingsmiddel.h 
    interface/generated/XmlVoedingsmiddeldef.h 
    interface/generated/XmlVoedingsmiddeldefReader.h 
    interface/generated/XmlVoedingsmiddeldefs.h 
    interface/generated/XmlVoedingsmiddeldefsReader.h 
    interface/generated/XmlVoedingsmiddeldefsWriter.h 
    interface/generated/XmlVoedingsmiddeldefWriter.h 
    interface/generated/XmlVoedingsmiddelReader.h 
    interface/generated/XmlVoedingsmiddelWriter.h 
    interface/generated/XmlVoedingswaarde.h 
    interface/generated/XmlVoedingswaardeReader.h 
    interface/generated/XmlVoedingswaardeWriter.h 
    interface/generated/XmlWeek.h 
    interface/generated/XmlWeekReader.h 
    interface/generated/XmlWeekWriter.h 
) 

add_library(Generated2024 ${SOURCES} ${HEADERS})

add_compile_definitions(_UNICODE UNICODE _LIB)
add_compile_options(/finput-charset=UTF-8 /fexec-charset=UTF-8 /JMC /permissive- /GS /analyze- /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MDd /FC /EHsc /nologo /diagnostics:column)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(NDEBUG)
endif()

target_include_directories(Generated2024 PUBLIC
    interface/generated
    C:/Projects/VC2022/xerces280/src
)
