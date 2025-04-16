#pragma once

#include "IFoodDefinitionRepository.h"
#include "Repository.h"

namespace weight {

class IStringRepository;
class VMDefinitie;

class FoodDefinitionRepository
    : public IFoodDefinitionRepository
    , private Repository<VMDefinitie> {
public:
    virtual ~FoodDefinitionRepository() override = default;
    FoodDefinitionRepository();

    bool Has(const std::string& name) const override;
    VMDefinitie* Find(const std::string& name) const override;
    bool Add(std::unique_ptr<VMDefinitie> definition) override;
    bool Remove(const std::string& name) override;
    void Clear() override;
    std::vector<VMDefinitie*> GetAll() const override;

    std::shared_ptr<IStringRepository> GetUnitRepository() const noexcept override { return m_units; }
    std::shared_ptr<IStringRepository> GetCategoryRepository() const noexcept override { return m_categories; }
    std::shared_ptr<IStringRepository> GetBrandRepository() const noexcept override { return m_brands; }

private:
    std::shared_ptr<IStringRepository> m_units;
    std::shared_ptr<IStringRepository> m_categories;
    std::shared_ptr<IStringRepository> m_brands;


};

} // namespace weight
