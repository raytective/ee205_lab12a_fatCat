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
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

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
    Weight::bIsKnown = true;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    /// CONVERT FROM WEIGHT UNITS TO HELD WEIGHT
    isWeightValid(newWeight);
    Weight::weight = newWeight;
    unitOfWeight = weightUnits;
    Weight::bIsKnown = true;
}

void Weight::setMaxWeight(float newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
    bHasMax = true;
}


float Weight::getWeight() const noexcept {
    if(!bIsKnown)
        return ::UNKNOWN_WEIGHT;

    return weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    float newWeight = convertWeight( Weight::weight, unitOfWeight, weightUnits );

    return newWeight;
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
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}


///////// CONSTRUCTORS //////////
/// idk try and figure out what works best for these dudes
Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    setWeight(::UNKNOWN_WEIGHT);
    setMaxWeight(::UNKNOWN_WEIGHT);
}

Weight::Weight(float newWeight) {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = POUND;
    setWeight(newWeight);
    setMaxWeight(::UNKNOWN_WEIGHT);
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    setWeight(::UNKNOWN_WEIGHT);
    setMaxWeight(::UNKNOWN_WEIGHT);
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    setWeight(newWeight);
    setMaxWeight(::UNKNOWN_WEIGHT);
}

Weight::Weight(float newWeight, float newMaxWeight): Weight( newWeight ) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = POUND;
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight): Weight( newUnitOfWeight) {
    bIsKnown = false;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    setWeight(::UNKNOWN_WEIGHT);
    setMaxWeight(newMaxWeight);
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}


///////// VALIDATION //////////
bool Weight::isWeightValid(float checkWeight) const noexcept {
    if( checkWeight <= 0 && checkWeight != ::UNKNOWN_WEIGHT) {
        return false;
    }
    if( checkWeight > maxWeight ) {
        return false;
    }

    return true;
}

bool Weight::validate() const noexcept {
    if( !isWeightValid( Weight::weight )) {
        return false;
    }

    return false;
}










///////// THIS SHOULD ALL BE FIND HOPEFULLY ////////




bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    // Sus about this one
    this->weight += rhs_addToWeight;
    return *this;
}

std::ostream &operator<<(std::ostream &lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND:
            return lhs_stream << POUND_LABEL;
        case Weight::KILO:
            return lhs_stream << KILO_LABEL;
        case Weight::SLUG:
            return lhs_stream << SlUG_LABEL;
        default:
            throw out_of_range("The unit can't be mapped to a string");
    }
}

std::ostream &operator<<(std::ostream &lhs_stream, const Weight &rhs_Weight) {
    float theLastNumberIprintedOut = 0 ;

    if( rhs_Weight.bIsKnown == false && rhs_Weight.hasMaxWeight() == false ) {
        lhs_stream << "Unknown";
    }

    if( rhs_Weight.bIsKnown == true && rhs_Weight.hasMaxWeight() == false ) {
        lhs_stream << rhs_Weight.getWeight() << " " << rhs_Weight.getWeightUnit();
        theLastNumberIprintedOut = rhs_Weight.getWeight();
    }

    if( rhs_Weight.bIsKnown == true && rhs_Weight.hasMaxWeight() == true ) {
        lhs_stream << rhs_Weight.getWeight() << " out of " << rhs_Weight.getMaxWeight() << " " << rhs_Weight.getWeightUnit();
        theLastNumberIprintedOut = rhs_Weight.getWeight();
    }

    if( rhs_Weight.bIsKnown == false && rhs_Weight.hasMaxWeight() == true ) {
        lhs_stream << "Unknown out of " << rhs_Weight.getMaxWeight() << " " << rhs_Weight.getWeightUnit();
        theLastNumberIprintedOut = rhs_Weight.getMaxWeight();
    }

    if(theLastNumberIprintedOut > 1 ) {
        lhs_stream << "s";
    }
    return lhs_stream;
}

void Weight::dump() const noexcept {
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" ) << this << endl ;
    FORMAT_LINE( "Weight", "isKnown" ) << bIsKnown << endl ;
    FORMAT_LINE( "Weight", "weight" ) << getWeight() << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << Weight::unitOfWeight << endl ;
    FORMAT_LINE( "Weight", "hasMax" ) << bHasMax << endl ;
    FORMAT_LINE( "Weight", "maxWeight" ) << getMaxWeight() << endl ;

}