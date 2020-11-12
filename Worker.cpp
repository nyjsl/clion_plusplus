//
// Created by xiaolian on 2020/11/12.
//

#include "Worker.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// must implement virtual destructor
Worker::~Worker()  {}

void Worker::Data() const {
    cout << "Name: "<< fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get()!='\n'){
        continue;
    }
}

void Worker::Set() {
    cout << "Enter worker's name:";
    Worker::Get();
}

void Worker::Show() const {
    cout << "Category:waiter\n";
    Worker::Data();
}

void Waiter::Set() {
    cout <<"Enter waiter's name ";
    Worker::Data();
    Data();
}

void Waiter::Data() const {
    cout << "Panache rating: "<< panche << endl;
}

void Waiter::Get() {
    cout << "Enter waiter's panche rating:";
    cin >> panche;
    while (cin.get() != '\n') {
        continue;;
    }
}

void Waiter::Show() const {
    cout << "Categor : waiter\n";
    Worker::Show();
    cout << "Panache rating: " << panche << "\n";
}

char * Singer::pv[] = {"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::Set() {
    cout << "Enter singer's name";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout << "Categor: singer \n";
    Worker::Data();
    Data();
}

void Singer::Data() const {
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get() {
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i <<": " <<pv[i] << " ";
        if (i % 4 == 3) {
            cout << endl;
        }

    }
    if (i % 4 != 0) {
        cout << endl;
    }
    while (cin >> voice && (voice < 0 || voice >= Vtypes)) {
        cout << "Please enter a value >=0 and <" << Vtypes << endl;
    }
    while (cin.get() != '\n') {
        continue;
    }
}

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get() {
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Set() {
    cout << "Enter singing waiter's name: ";
    Worker::Set();
    Get();
}

void SingingWaiter::Show() const {
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}
