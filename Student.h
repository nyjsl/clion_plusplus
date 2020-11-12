//
// Created by xiaolian on 2020/11/12.
//

#ifndef CLION_CPLUSPLUS_STUDENT_H
#define CLION_CPLUSPLUS_STUDENT_H

#include <iostream>
#include <valarray>
#include <string>
/**
 * 初始化顺序
 *  ，当初始化列表包含多个项目时，这些项目被初始化的顺序为它们被声明的顺序，而不是它们在初始化列表中的顺序。
 *
 *  私有多继承,注释掉的代码为不是使用继承是的版本
 */
class Student :private std::string,private std::valarray<double>{
private:
    typedef std::valarray<double> ArrayDb;
//    std::string name;
//    ArrayDb scores;
    std::ostream &arr_out(std::ostream & os) const;
public:

//    Student():name("Null Student"),scores(){}
//    explicit Student(const std::string & s):name(s),scores(){}
//    explicit Student (int n):name("Nully"),scores(n){}
//    Student(const std::string & s,int n):name(s),scores(n){}
//    Student(const std::string & s,const ArrayDb & a):name(s),scores(a){}
//    Student(const char*  str,const double *pd,int n):name(str),scores(pd,n){}

    Student():std::string("Null Student"),ArrayDb(){}
    explicit Student(const std::string & s):std::string(s),ArrayDb(){}
    explicit Student (int n):std::string("Nully"),ArrayDb(n){}
    Student(const std::string & s,int n):std::string(s),ArrayDb(n){}
    Student(const std::string & s,const ArrayDb & a):std::string(s),ArrayDb(a){}
    Student(const char*  str,const double *pd,int n):std::string(str),ArrayDb(pd,n){}

    ~Student(){}

    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    //output
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    //input
    friend std::istream &operator>>(std::istream &is,Student& stu);
    //getline
    friend std::istream & getline(std::istream & is,Student & stu);

};


#endif //CLION_CPLUSPLUS_STUDENT_H
