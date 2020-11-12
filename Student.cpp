//
// Created by xiaolian on 2020/11/12.
//

#include "Student.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

std::ostream &Student::arr_out(ostream &os) const {
    int i;
    int lim = ArrayDb ::size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << ArrayDb ::operator[](i) << " ";
            if (i % 5 == 4) {
                os << endl;
            }

        }
        if (i % 5 != 0) {
            os << endl;
        }
    }else{
        os << "Empyt array";
    }
    return os;
}

double Student::Average() const {
    if (ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    }
    return 0;
}

const std::string &Student::Name() const {
    return (const string &) * this;
}

double &Student::operator[](int i) {
    return ArrayDb ::operator[](i);
}

double Student::operator[](int i) const {
    return ArrayDb::operator[](i);
}

std::ostream &operator<<(ostream &os, const Student &student) {
    os << "Scores for "<< (const string&) student << ":\n";
    student.arr_out(os);
    return os;
}

std::istream &operator>>(istream &is, Student &stu) {
    is >> (string&) stu;
    return is;
}

std::istream & getline(istream &is, Student &stu) {
    getline(is, (string&) stu);
    return is;
}

