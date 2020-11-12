//
// Created by xiaolian on 2020/11/12.
//

#ifndef CLION_CPLUSPLUS_WORKER_H
#define CLION_CPLUSPLUS_WORKER_H

#include <string>
// an abstract base class
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
