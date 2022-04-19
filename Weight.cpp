///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Rachel Watanabe <rkwatana@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
using namespace std;

static const float UNKNOWN_WEIGHT = -1;
static const float KILOS_IN_A_POUND = 0.453592;
static const float SLUGS_IN_A_POUND = 0.031081;
static const std::string POUND_LABEL = "Pound";
static const std::string KILO_LABEL = "Kilo";
static const std::string SlUG_LABEL = "Slug";

///// CONVERSIONS /////
float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / ::KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * ::KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / ::SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * ::SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float newWeight;

    switch( fromUnit )
    {
        case POUND:
            newWeight = fromWeight;
            break;
        case KILO:
            newWeight = fromKilogramToPound( fromWeight );
            break;
        case SLUG:
            newWeight = fromSlugToPound( fromWeight );
            break;
    }

    switch( toUnit )
    {
        case POUND:
            break;
        case KILO:
            newWeight = fromPoundToKilogram( newWeight );
            break;
        case SLUG:
            newWeight = fromPoundToSlug( newWeight );
            break;
    }

    return newWeight;
}


///// GETTERS/SETTERS /////
void Weight::setWeight(float newWeight) {
    isWeightValid( newWeight );
    Weight::weight = newWeight;
    Weight::blsKnown = true;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    isWeightValid( newWeight );
    Weight::weight = newWeight;
    unitOfWeight = weightUnits;
    Weight::blsKnown = true;
}


float Weight::getWeight() const noexcept {
    if(!blsKnown)
        return ::UNKNOWN_WEIGHT;

    return weight;
}


float Weight::getMaxWeight() const noexcept {
    if( !bHasMax )
        return ::UNKNOWN_WEIGHT;

    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

bool Weight::isWeightKnown() const noexcept {
    return blsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}


///// CONSTRUCTORS /////
Weight::Weight() noexcept {
    setWeight( ::UNKNOWN_WEIGHT );
}

Weight::Weight(float newWeight) {
    setWeight( newWeight );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    //FIGURE OUT WHAT THIS IS HELLO?
    setWeight( ::UNKNOWN_WEIGHT, newUnitOfWeight );
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight( newWeight, newUnitOfWeight );

}

Weight::Weight(float newWeight, float newMaxWeight): Weight( newWeight ) {
    setMaxWeight( newMaxWeight );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight): Weight( newUnitOfWeight) {
    setMaxWeight( newMaxWeight );
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setWeight( newWeight, newUnitOfWeight );
    setMaxWeight( newMaxWeight );
}

void Weight::setMaxWeight(float newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}


bool Weight::isWeightValid(float checkWeight) const noexcept {
    if( checkWeight <= 0 ) {
        return false;
    }
    if( checkWeight > maxWeight ) {
        return false;
    }

    return true;

}