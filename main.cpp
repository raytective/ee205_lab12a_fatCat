///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Rachel Watanabe <rkwatana@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Weight.h"
#define PROGRAM_NAME "fatCat"
using namespace std;

int main() {

    cout << "Starting " << PROGRAM_NAME << endl;

    // isKnown = false , hasMax = false
    Weight emptyCat = Weight();
    // isKnown = true , hasMax = false
    Weight halfCat = Weight(10.0 );
    //isKnown = false , hasMax = false
    Weight slimCat = Weight(Weight::SLUG );
    // isKnown = true , hasMax = true
    Weight fullCat = Weight(5.0, Weight::KILO, 50.0);

    emptyCat.dump();
    halfCat.dump();
    slimCat.dump();
    fullCat.dump();

   #ifdef DEBUG

    cout << "Is weight known? false = " << emptyCat.isWeightKnown() << endl;
    cout << "Is weight known? true = " << fullCat.isWeightKnown() << endl << endl;

    cout << "Has max weight? false = " << emptyCat.hasMaxWeight() << endl;
    cout << "Has max weight? true = " << fullCat.hasMaxWeight() << endl << endl;

    emptyCat.setWeight(12, Weight::KILO );
    cout << "New weight for emptyCat is " << emptyCat.getWeight() << endl << endl;

    cout << "Old weight for fullCat = " << fullCat.getWeight() << endl;
    fullCat.setWeight(15 );
    cout << "New weight for fullCat = 15 = " << fullCat.getWeight() << endl;
    fullCat.setWeight(15, Weight::POUND );
    cout << "New weight for fullCat = 33.069 = " << fullCat.getWeight() << endl << endl;

   #endif

   cout << "Ending " << PROGRAM_NAME << endl;

    return 0;
}
