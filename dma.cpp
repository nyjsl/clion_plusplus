//
// Created by xiaolian on 2020/11/11.
//
#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA() {
    delete[] label;
}

baseDMA &baseDMA::operator=(const baseDMA &rs) {
    if (this == &rs) {
        return * this;
    }
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
    os << "Label: "<< rs.label << std::endl;
    os << "Rating:" << rs.rating<< std::endl;
    return os;
}

lackDMA::lackDMA(const char *l, int r, char *c):baseDMA(l,r) {
    std::strncpy(clor,c,39);
    clor[39] = '\0';
}

lackDMA::lackDMA(const char *c, const baseDMA &rs):baseDMA(rs){
    std::strncpy(clor, c, COL_LEN - 1);
    clor[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lackDMA &dma) {
    os<<(const baseDMA &) dma;
    os << "Color: "<<dma.clor<<std::endl;
    return os;
}

//hasDMA methods



hasDMA::hasDMA(const char *s, const char *l, int r):baseDMA(l,r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs):baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
// invoke base class copy constructor
hasDMA::hasDMA(const hasDMA &rs) :baseDMA(rs){
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA &hasDMA::operator=(const hasDMA &rs) {
    if (this == &rs) {
        return *this;
    }
    //copy base protion
    baseDMA::operator=(rs);
    //prepare for new style
    delete [] style;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &dma) {
    os << (const baseDMA&) dma;
    os << "Style: "<< dma.style << std::endl;
    return os;
}
