//
// Created by xiaolian on 2020/11/9.
//

#ifndef CLION_CPLUSPLUS_BRASS_H
#define CLION_CPLUSPLUS_BRASS_H
#include <iostream>
#include <string>
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
