//
// Created by xiaolian on 2020/11/5.
//

#ifndef CLION_CPLUSPLUS_STRINGBAD_H
#define CLION_CPLUSPLUS_STRINGBAD_H


#include <iostream>

// 在构造函数和析构函数中正确地使用new 和 delete
/**
 * StringBad类的问题是由特殊成员函数引起的。这些成员函数是自动定义的
 * C++默认提供了下面这些成员函数：
 *  默认构造函数，如果没有定义构造函数
 *  默认析构函数，如果没有定义
 *  复制构造函数，如果没有定义 ，当函数按值传递对象，或函数返回对象时，都将使用复制构造函数
 *  记住，按值传递将创建原始变量的一个副本。
 *  默认的复制构造函数，逐个复制非静态成员（成员复制也称浅复制），复制的是成员的值
 *  赋值运算符，如果没有定义
 *  地址运算符，如果没有定义
 */
class StringBad{
private:
    char * str; // pointer to string
    int len;
    static int num_strings; //number of objects
public:
    StringBad(const char* s); //constructor
    StringBad(); // default constructor
    ~StringBad(); // destructor

    //定义一个显示复制构造函数以解决问题
    StringBad(const StringBad & st);

    // friend function
    friend std::ostream & operator<<(std::ostream & os,const StringBad & st);
    // 赋值云素服
    StringBad & operator=(const StringBad & st);
};

#endif //CLION_CPLUSPLUS_STRINGBAD_H
