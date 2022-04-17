///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Rachel Watanabe <rkwatana@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <string>

class Weight {
public:
    static const float UNKOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SlUG_LABEL;

public:
    enum UnitOfWeight{ POUND, KILO, SLUG };

    static float fromKilogramToPound (float kilogram) noexcept;
    static float fromPoundToKilogram (float pound) noexcept;
    static float fromSlugToPound (float slug) noexcept;
    static float fromPoundToSlug (float pound ) noexcept;
    static float convertWeight (float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

public:
    Weight () noexcept;
    Weight (float newWeight);
    Weight (UnitOfWeight newUnitOfWeight) noexcept;
    Weight (float newWeight, UnitOfWeight newUnitOfWeight);
    Weight (float newWeighht, float newMaxWeight);
    Weight (UnitOfWeight newUnitOfWeighht, float newMaxWeight);
    Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;

    UnitOfWeight getWeightUnit() const noexcept;

    void setWeight (float newWeight);
    void setWeight (float newWeight, UnitOfWeight weightUnits);

    bool isWeightValid (float checkWeight) const noexcept;
    bool validate () const noexcept;
    void dump () const noexcept;
    bool operator== (const Weight &rhs_Weight) const;
    bool operator< (const Weight &rhs_Weight) const;

    Weight& operator+= (float rhs_addToWeight);

private:
    void setMaxWeight (float newMaxWeight);

    bool blsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;
    float weight{};
    float maxWeight{};

};

