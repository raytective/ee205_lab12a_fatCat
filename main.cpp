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

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    // isKnown = false , hasMax = false
    Weight emtpyCat = Weight();
    // isKnown = true , hasMax = false
    Weight halfCat = Weight(10.0 );
    // isKnown = false , hasMax = false
    Weight slimCat = Weight(Weight::SLUG );
    // isKnown = true , hasMax = true
    Weight fullCat = Weight(5.0, Weight::KILO, 50.0);

    emtpyCat.dump();
    halfCat.dump();
    slimCat.dump();
    fullCat.dump();




    return 0;
}
