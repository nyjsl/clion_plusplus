//
// Created by xiaolian on 2020/11/9.
//

#ifndef CLION_CPLUSPLUS_TABLE_TENNIS_H
#define CLION_CPLUSPLUS_TABLE_TENNIS_H
/**
 * simple base class
 */
#include <string>
using std::string;
class TableTannisPlayer{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTannisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
    void Name() const;
    bool Hastable() const { return hasTable;}
    void ResetTable(bool  v){ hasTable = v; }
};


class ReatedPalyer:public TableTannisPlayer{

private:
    unsigned int rating;
public:
    ReatedPalyer(unsigned int r=0,const string &fn = "none", const string &ln = "none", bool ht = false);
    ReatedPalyer(unsigned int r,const TableTannisPlayer & tp);

    unsigned int Rating() const { return rating; }

    void ResetRating(unsigned int r){ rating = r; }

};

#endif //CLION_CPLUSPLUS_TABLE_TENNIS_H
