#include <iostream>
#include "stonewt.h"

#include "stringbad.h"


void cellme1(StringBad &rsb); //pass by refreence
void cellme2(StringBad sb);   //pass by value
using std::cout;
int main() {
    cout << "Hello, World!" << std::endl;

//    Stonewt myCat;
//    myCat = 19.6; // not valid if Stonewt(double) is declared as explicit
//    myCat.show_stn();
//    myCat = Stonewt(29.6);
//    myCat.show_stn();
//
//    Stonewt poppings(9, 2.8);
//
//    double p_wt = poppings; // implicit conversion
//
//    std::cout << "Poppings: " << p_wt << " pounds.\n";
//
//    std::cout << "Convert to int => ";
//    std::cout << "Poppings: " << int(poppings) << ". pounds.\n";
    using std::endl;{
        cout <<"Starting an inner block\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headlien2("Lettuce Prey");
        StringBad sports("Spinach Levaves bow1 for Dollars");
        cout << "headline1: "<<headline1<<endl;
        cout << "headlien2: "<<headlien2<<endl;
        cout << "sports: "<<sports<<endl;
        cellme1(headline1);
        cout << "headline1: "<<headline1<<endl;
        cellme2(headlien2);
        cout << "headlien2: "<<headlien2<<endl;
        cout << "Initialize one object to another:\n";
        //调用复制构造函数
        StringBad sailor = sports; //call StringBad(const StringBad &)
        cout << "sailor: "<<sailor<<endl;
        cout << "Assigin one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: "<<knot<<endl;
        cout << "Exiting the block.\n";



    }



    return 0;
}

void cellme1(StringBad &rsb){
    cout << "String passed by refreence:\n";
    cout << "   \"" << rsb << "\"\n";
}

void cellme2(StringBad sb){
    cout << "String passed by val:\n";
    cout << "   \"" << sb << "\"\n";
}

