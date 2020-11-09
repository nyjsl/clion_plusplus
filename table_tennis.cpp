//
// Created by xiaolian on 2020/11/9.
//

#include "table_tennis.h"
#include <iostream>
//成员初始化列表语法
TableTannisPlayer::TableTannisPlayer(const string &fn, const string &ln, bool ht):firstname(fn),lastname(ln),
hasTable(ht){

}

void TableTannisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

ReatedPalyer::ReatedPalyer(unsigned int r, const string &fn, const string &ln, bool ht):rating(r),TableTannisPlayer(fn,ln,ht){

}

ReatedPalyer::ReatedPalyer(unsigned int r, const TableTannisPlayer &tp):rating(r),TableTannisPlayer(tp) {

}
