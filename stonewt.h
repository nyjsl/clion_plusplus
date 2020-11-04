//
// Created by xiaolian on 2020/11/4.
//

#ifndef CLION_CPLUSPLUS_STONEWT_H
#define CLION_CPLUSPLUS_STONEWT_H
class Stonewt{
private:
    enum {Lbs_per_stn = 14}; // ponuds per stone
    int stone;
    double pds_left;
    double pounds;
public:
    // no implicit conversions allowed
    // 在构造函数声明中使用explicit可防止隐式转换，而且只允许显示转换
    explicit Stonewt(double lbs); // constructor for double pounds
    //创建转换函数,将Stonewt对象转换为int类型和double类型的函数
    //conversion functions
    operator int() const;
    operator double() const;
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;


};

#endif //CLION_CPLUSPLUS_STONEWT_H
