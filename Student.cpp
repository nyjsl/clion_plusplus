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
    int lim = scores.size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << scores[i] << " ";
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
    if (scores.size() > 0) {
        return scores.sum() / scores.size();
    }
    return 0;
}

const std::string &Student::Name() const {
    return name;
}

double &Student::operator[](int i) {
    return scores[i];
}

double Student::operator[](int i) const {
    return scores[i];
}

std::ostream &operator<<(ostream &os, const Student &student) {
    os << "Scores for "<< student.name << ":\n";
    student.arr_out(os);
    return os;
}

std::istream &operator>>(istream &is, Student &stu) {
    is >> stu.name;
    return is;
}

std::istream & getline(istream &is, Student &stu) {
    getline(is, stu.name);
    return is;
}

