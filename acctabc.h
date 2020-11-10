//
// Created by xiaolian on 2020/11/10.
//

#ifndef CLION_CPLUSPLUS_ACCTABC_H
#define CLION_CPLUSPLUS_ACCTABC_H

#include <iostream>
#include <string>
//abstract base class
class AcctABC{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting{
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const{ return fullName; }
    long AcctNum() const { return acctNum; }

    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string &s = "Nullbody",long an = -1,double bal=0.0);

    void Deposit(double amt);

    //pure vitual function end with =0
    virtual void WithDraw(double amt) =0;
    virtual void ViewAcct() const = 0;
    double Balance() const{ return balance; }
    virtual ~AcctABC();

};

class BrassA :public AcctABC{
public:
    BrassA(const std::string &s = "Nullbody",long an = -1,double bal=0.0)
    :AcctABC(s,an,bal){}

    virtual void WithDraw(double amt) ;
    virtual void ViewAcct() const;

    virtual ~BrassA() {}
};

class BrassPlusA : public AcctABC{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlusA(const std::string &s = "Nullbody",long an = -1,double bal=0.0
            ,double ml = 500,double r = 0.10);
    BrassPlusA(const BrassA & ba
            ,double ml = 500,double r = 0.10);
    virtual void WithDraw(double amt) ;
    virtual void ViewAcct() const;

    void ResetMax(double m){ maxLoan = m; }

    void ResetRate(double r){ rate = r; }

    void ResetOwes(){ owesBank = 0; }

};

#endif //CLION_CPLUSPLUS_ACCTABC_H
