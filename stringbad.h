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
 *
 *
 *
 *  对于指向的内存是由new分配的所有类成员，都应在类的析构函数中对其使用delete，该运算符将释放分配的内存
 *  如果析构函数通过对指针类成员使用delete释放内存，则每个构造函数都应该使用new来初始化指针，或者将它设置为空指针
 *  构造函数中要么使用new[] 要么使用new,而不能混用。
 *  应定义一个分配内存的复制构造函数，这样程序将能够将类对象初始化为另一个类对象。这种构造函数的原型通常如下：
 *      className(const className &)
 *
 *  应定义一个能重载赋值运算符的类成员函数，其函数定义如下
 *      c_name & cname::operator=(cosnt c_name & cn)
 *      {
 *          if(this == &cn){
 *           return *this;
 *          }
 *           delete [] c_pointer;
 *           c_pointer = new type_name[size]
 *           //then copy dota pointed to by cn.c_pointer to
 *           //location pointer to by c_pointer
 *           //
 *          return * this;
      }
 */
class StringBad{
private:
    char * str; // pointer to string
    int len;
    static int num_strings; //number of objects
    static const int CINLIM = 80; // cin input limit
public:
    StringBad(const char* s); //constructor
    StringBad(); // default constructor
    ~StringBad(); // destructor

    //定义一个显示复制构造函数以解决问题
    StringBad(const StringBad & st);

    // friend function
    friend std::ostream & operator<<(std::ostream & os,const StringBad & st);
    friend std::istream & operator>>(std::istream & os,StringBad & st);
    // 赋值运算符
    StringBad & operator=(const StringBad & st);
    StringBad & operator=(const char * s);
};

#endif //CLION_CPLUSPLUS_STRINGBAD_H
