#include <iostream>
#include "stonewt.h"

#include "stringbad.h"
#include "Queue.h"
#include <cstdlib>
#include <ctime>
void cellme1(StringBad &rsb); //pass by refreence
void cellme2(StringBad sb);   //pass by value
bool newcustomer(double x);
void bank();
using std::cout;
using std::cin;
using std::ios_base;
using std::endl;
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
//    using std::endl;
//    {
//        cout <<"Starting an inner block\n";
//        StringBad headline1("Celery Stalks at Midnight");
//        StringBad headlien2("Lettuce Prey");
//        StringBad sports("Spinach Levaves bow1 for Dollars");
//        cout << "headline1: "<<headline1<<endl;
//        cout << "headlien2: "<<headlien2<<endl;
//        cout << "sports: "<<sports<<endl;
//        cellme1(headline1);
//        cout << "headline1: "<<headline1<<endl;
//        cellme2(headlien2);
//        cout << "headlien2: "<<headlien2<<endl;
//        cout << "Initialize one object to another:\n";
//        //调用复制构造函数
//        StringBad sailor = sports; //call StringBad(const StringBad &)
//        cout << "sailor: "<<sailor<<endl;
//        cout << "Assigin one object to another:\n";
//        StringBad knot;
//        knot = headline1;
//        cout << "knot: "<<knot<<endl;
//        cout << "Exiting the block.\n";
//    }

    bank();

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

bool newcustomer(double x) {
    return (std::rand()*x/RAND_MAX <1);
}

const int MIN_PER_HR = 60;
void bank() {
    std::srand(std::time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    cout << "Enter the number of simulation hours:";
    int hours ;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR;
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long servd = 0;
    long sum_Lin = 0;
    long wait_time = 0;
    long line_wait = 0;
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (line.isFull()) {
                turnaways++;
            }else{
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isEmpyt()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            servd++;
        }
        if (wait_time > 0) {
            wait_time--;
        }
        sum_Lin+=line.queuecount();
    }

    if(customers>0) {
        cout << "customers accepted " <<customers << std::endl;
        cout << "customers served " <<servd << std::endl;
        cout << "turnaways " <<turnaways << std::endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_Lin/cyclelimit << endl;
        cout << "average wait time: "
             << (double) line_wait / servd << " minutes \n";

    }else{
        cout << "No customers! \n";
    }
    cout << "Done!\n";
}

