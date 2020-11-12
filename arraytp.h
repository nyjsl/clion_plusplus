//
// Created by xiaolian on 2020/11/12.
//

#ifndef CLION_CPLUSPLUS_ARRAYTP_H
#define CLION_CPLUSPLUS_ARRAYTP_H

#include <iostream>
#include <cstdlib>
/**
 *  T为类型参数,int指出 n的类型为int
 *  这种参数(指定特殊的类型而不是用作泛型名),称为非类型或表达式参数
 *
 *  表达式参数有一些限制.表达式参数可以是整型,枚举,引用或指针.
 *  另外模板参数不能修改参数的值,也不能使用参数地地址
 *
 *  与Stack中使用构造函数方法相比,这种改变数组大小的方法有一个优点.
 *  构造函数方法使用的是通过new和delete管理的堆内存,而表达式参数方法使用的是为自动变量维护的内存栈.
 *  这样执行速度更快
 *
 *  表达式参数方法的主要缺点是,每种数组大小都将生成自己的模板
 * @tparam T
 * @tparam n
 */
template <class T,int n>
class ArrayTP{
private:
    T arr[n];
public:
    ArrayTP(){};
    explicit ArrayTP(const T & v);

    virtual T &operator[](int i);
    virtual T operator[](int i)const;
};

template<class T, int n>
ArrayTP<T, n>::ArrayTP(const T &v) {
    for (int i = 0; i < n; i++) {
        arr[i] = v;
    }
}

template<class T, int n>
T &ArrayTP<T, n>::operator[](int i) {
    if (i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template<class T, int n>
T ArrayTP<T, n>::operator[](int i) const {
    if (i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

#endif //CLION_CPLUSPLUS_ARRAYTP_H
