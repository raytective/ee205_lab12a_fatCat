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

    // make a few weights??
    Weight nonWeight = Weight();
    Weight baseWeight = Weight( 12.5 );
    Weight maxWeight = Weight(Weight::KILO, 50);


    return 0;
}
