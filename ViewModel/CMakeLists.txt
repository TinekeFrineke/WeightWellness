
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/msvc2022_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) # Enables automatic resource handling

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Quick Widgets)

set(SOURCES
    source/Day.cpp
    source/FoodModel.cpp
    source/FoodListModel.cpp
    source/PersonalData.cpp
    source/ViewModel.cpp
    source/ViewModelUtilities.cpp
    source/Week.cpp
    source/ViewModelFactory.cpp
)

set(HEADERS
    interface/viewModel/ViewModelFactory.h
    interface/viewModel/IDay.h
    interface/viewModel/IFoodListModel.h
    interface/viewModel/IPersonalData.h
    interface/viewModel/IViewModel.h
    interface/viewModel/IWeek.h
    header/Day.h
    header/FoodModel.h
    header/FoodListModel.h
    header/ISettableDay.h
    header/ISettableWeek.h
    header/IViewModelDay.h
    header/IViewModelWeek.h
    header/PersonalData.h
    header/ViewModel.h
    header/ViewModelUtilities.h
    header/Week.h
)

add_library(ViewModel
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(ViewModel PUBLIC
    interface/viewmodel
)

target_include_directories(ViewModel PRIVATE
    header
    ${CMAKE_SOURCE_DIR}/Model/interface
    C:/Projects/VC2022/Utilities/include
)

target_link_libraries(ViewModel
    Qt6::Core
    Qt6::Quick
    Qt6::Widgets
)

set(MOC_BUILD_PATH ${CMAKE_SOURCE_DIR}/build/ViewModel/ViewModel_autogen/)

source_group(Qml FILES
    ${MOC_BUILD_PATH}mocs_compilation_Debug.cpp
    ${MOC_BUILD_PATH}mocs_compilation_MinSizeRel.cpp
    ${MOC_BUILD_PATH}mocs_compilation_Release.cpp
    ${MOC_BUILD_PATH}mocs_compilation_RelWithDebInfo.cpp
)

set_target_properties(ViewModel PROPERTIES FOLDER "WeightControl")
