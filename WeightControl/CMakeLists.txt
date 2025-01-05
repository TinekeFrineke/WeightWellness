
set(SOURCES
    source/WeightControl.cpp
)

set(HEADERS
    header/WeightControl.h
) 
 
 
add_executable(WeightControl ${SOURCES} ${HEADERS})


target_include_directories(WeightControl PUBLIC header)