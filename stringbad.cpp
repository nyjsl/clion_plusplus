//
// Created by xiaolian on 2020/11/5.
//

#include "stringbad.h"
#include <cstring>
using std::cout;
// initizlizing static class member
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char(len+1); // allot storage
    std::strcpy(str,s);
    num_strings++;
    cout << num_strings << ":\"" << str << "\" object created\n";
}
// 在构造函数中使用new来分配内存时，必须在相应的析构函数中使用delete来释放内存。
// 如果使用new【】 来分配内存，则应使用delete【】 来释放内存
StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str,"C++"); // default string
    num_strings++;
    cout << num_strings << ":\"" << str << "\" default object created\n";
}
//必须定义复制构造函数的原因在于，一些类成员使用new初始化的，指向数据的指针，而不是数据本身
StringBad::StringBad(const StringBad &st) {
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str); // copy string to new location
    cout << num_strings << " \"" <<str << "\" object created\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted,";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

StringBad & StringBad::operator=(const StringBad &st) {
    if(this == &st){
        return * this;
    }
    delete[] str; // free old string
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return * this;
}


std::ostream & operator<<(std::ostream & os,const StringBad & st){
    os << st.str;
    return os;
}