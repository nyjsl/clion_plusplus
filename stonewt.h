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
    Stonewt(double lbs); // constructor for double pounds
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
};

#endif //CLION_CPLUSPLUS_STONEWT_H
