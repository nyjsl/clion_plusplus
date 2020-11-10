//
// Created by xiaolian on 2020/11/9.
//

#ifndef CLION_CPLUSPLUS_BRASS_H
#define CLION_CPLUSPLUS_BRASS_H
#include <iostream>
#include <string>
/**
 * 有关虚函数的注意事项
 *
 *      在基类方法的声明中使用关键字virtual可使该方法在基类以及所有的
 *    派生类（包括从派生类派生出来的类）中是虚的。
 *
 *      如果使用指向对象的引用或指针来调用虚方法，程序将使用对象类型定义的方法
 *    而不使用引用或指针类型定义的方法。这称为动态编联或晚期编联。
 *    这种行为非常重要，因为这样基类指针或引用可以指向派生类对象
 *
 *      如果定义的类将被作为基类，则应将那些要在派生类中重新定义的类方法声明为虚的。
 *
 *
 *     析构函数
 *
 *        虚构函数应该是虚函数，除非类不用做基类
 *
 *        顺便说一下，给类定义一个虚西沟函数并非错误，即时这个类不用做基类；这只是一个效率方面的问题。
 *
 *
 *      友元不能是虚函数，因为友元不是类成员，只有成员才能是虚函数
 */
class Brass{

private:
    std::string fullname;
    long acctNum;
    double balance;
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);

    void Deposit(double amt);
    //使用虚方法
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    //为何需要虚析构函数
    //确保正确的西沟函数序列被调用
    virtual ~Brass(){}
};

class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:

    BrassPlus(const std::string &s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.111125);

    BrassPlus(const Brass &ba, double ml = 500, double r = 0.111125);
    //使用虚方法
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;

    void ResetMax(double m){maxLoan = m;}
    void ResetRate(double r){ rate = r; }
    void ResetOwes(){ owesBank = 0; }

};

#endif //CLION_CPLUSPLUS_BRASS_H
