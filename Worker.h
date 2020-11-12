//
// Created by xiaolian on 2020/11/12.
//

#ifndef CLION_CPLUSPLUS_WORKER_H
#define CLION_CPLUSPLUS_WORKER_H

#include <string>
// an abstract base class

/**
 *  如果一个类从两个不同的类那里继承两个同名的成员,则需要在派生类中使用类限定符来区分它们.
 *
 *  如果一个类通过多种途径继承了一个非虚基类,则该类从每种途径分别继承非虚基类的一个实例.
 *  在某些情况下,这可能真是所希望的,但通常情况下,多个基类实例都是问题.
 *
 *  当派生类使用关键字virtual来指定派生时,基类就成为虚基类
 *
 *  主要变化是,从虚基类的一个或多个实例派生而来的类将只继承了一个基类对象,为实现这种特性必须满足其他要求
 *      有间接虚基类的派生类包含直接调用间接基类构造函数的构造函数,这对于间接非虚基类来说是非法的;
 *      通过优先规则决绝名称二义性
 */
class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:

    Worker():fullname("one one"),id(0L){}
    Worker(const std::string &s,long n):fullname(s),id(n){}
    //pure virtual destructor
    virtual ~Worker()=0;
    virtual void Set() = 0;
    virtual void Show() const = 0;

};
/**
 * 虚基类使得从多个类派生出的对象只继承一个基类对象.
 *
 * 如果类有间接虚基类,则除非只需要使用该虚基类的默认构造函数,否则必须显示地调用该虚基类的某个构造函数
 */
class Waiter: virtual public  Worker{
private:
    int panche;
protected:
    void Data() const;
    void Get();
public:
    Waiter():Worker(),panche(0){}
    Waiter(const std::string &s,long n,int p =0):Worker(s,n),panche(p){}
    Waiter(const Worker & wk,int p =0):Worker(wk),panche(p){}
    void Set();
    void Show() const;

};

class Singer:virtual public  Worker{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char* pv[Vtypes];
    int voice;
public:
    Singer():Worker(),voice(other){}
    Singer(const std::string & s,long n,int v = other):Worker(s,n),voice(v){}
    Singer(const Worker & wk,int v = other):Worker(wk),voice(v){}
    void Set() ;
    void Show() const ;
};

// mtultiple inheritance
class SingingWaiter: public Singer,public Waiter{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter(){}

    SingingWaiter(const std::string &s, long n, int p = 0,int v=other)
    :Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
    SingingWaiter(const Worker& wk,int p=0,int v = other)
    :Worker(wk),Waiter(wk,p),Singer(wk,v){}

    SingingWaiter(const Worker& wk,int p=0)
    :Worker(wk),Waiter(wk,p),Singer(wk){}

    void Set() ;
    void Show() const ;
};


#endif //CLION_CPLUSPLUS_WORKER_H
