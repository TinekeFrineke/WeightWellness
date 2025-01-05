
set(SOURCES
    source/BonusPointsMap.cpp
    source/Day.cpp
    source/Entity.cpp
    source/FoodDefinitionRepository.cpp
    source/Lot.cpp
    source/LotFactory.cpp
    source/Model.cpp
    source/ModelException.cpp
    source/NutritionalValue.cpp
    source/Observer.cpp
    source/Personalia.cpp
    source/PointsCalculator.cpp
    source/Portie.cpp
    source/Recept.cpp
    source/ReceptDefinitie.cpp
    source/RecipeRepository.cpp
    source/Repository.cpp
    source/Subject.cpp
    source/Voedingsmiddel.cpp
    source/VoedingsmiddelDefinitie.cpp
    source/Week.cpp
    source/WeekRepository.cpp
)

set(HEADERS
    interface/model/BonusPointsMap.h
    interface/model/Day.h
    interface/model/Entity.h
    interface/model/FoodDefinitionRepository.cpp
    interface/model/IFoodDefinitionRepository.h
    interface/model/ILotFactory.h
    interface/model/IObserver.h
    interface/model/IRecipeRepository.h
    interface/model/IRepository.h
    interface/model/ISubject.h
    interface/model/Item.h
    interface/model/IWeekRepository.h
    interface/model/Lot.h
    interface/model/LotFactory.h
    interface/model/ManualItem.h
    interface/model/Model.h
    interface/model/ModelException.h
    interface/model/Naam.h
    interface/model/NutritionalValue.h
    interface/model/Observer.h
    interface/model/Personalia.h
    interface/model/PointsCalculator.h
    interface/model/Portie.h
    interface/model/Recept.h
    interface/model/ReceptDefinitie.h
    interface/model/Repository.h
    interface/model/Subject.h
    interface/model/Voedingsmiddel.h
    interface/model/VoedingsmiddelDefinitie.h
    interface/model/Week.h
    interface/model/WWDefinitions.h
    interface/model/XmlDefinitions.h
) 
 
 
add_library(Model ${SOURCES} ${HEADERS})

target_include_directories(Model PUBLIC interface/model)