#include <iostream>
#include "stonewt.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    Stonewt myCat;
//    myCat = 19.6; // not valid if Stonewt(double) is declared as explicit
    myCat.show_stn();
    myCat = Stonewt(29.6);
    myCat.show_stn();

    Stonewt poppings(9, 2.8);

    double p_wt = poppings; // implicit conversion

    std::cout << "Poppings: " << p_wt << " pounds.\n";

    std::cout << "Convert to int => ";
    std::cout << "Poppings: " << int(poppings) << ". pounds.\n";

    return 0;
}
