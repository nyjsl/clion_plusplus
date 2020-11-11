//
// Created by xiaolian on 2020/11/11.
//

#ifndef CLION_CPLUSPLUS_DMA_H
#define CLION_CPLUSPLUS_DMA_H

#include <ostream>
// base class using dma
class baseDMA{
private:
    char * label;
    int rating;
public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &os, const baseDMA &rs) ;
};
// no destructor needed
// use implict copy constructor
// use implicit assigment operator
class lackDMA: public baseDMA{

private :
    enum {COL_LEN = 40};
    char clor[COL_LEN];
public:
    lackDMA(const char *l= "blank", int r = 0, char * c = "null") ;

    lackDMA(const char *c ,const baseDMA & rs);

    friend std::ostream &operator<<(std::ostream &os, const lackDMA &dma);

};
// derived class with DMA
class hasDMA : public baseDMA {
private:
    char * style;
public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &rs);
    ~hasDMA();

    hasDMA &operator=(const hasDMA &rs);

    friend std::ostream &operator<<(std::ostream &os, const hasDMA &dma);
};
#endif //CLION_CPLUSPLUS_DMA_H
