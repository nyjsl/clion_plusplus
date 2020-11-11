//
// Created by xiaolian on 2020/11/11.
//

#ifndef CLION_CPLUSPLUS_DMA_H
#define CLION_CPLUSPLUS_DMA_H

#include <ostream>
// base class using dma


/**
 * 类设计的回顾
 *
 *    编译期会自动生成一些共有成员函数
 *      1. 默认构造函数
 *         默认构造函数要么没有参数，要么所有的参数都有默认值
 *         如果没有定义任何构造函数，编译器将定义默认构造函数，让您能够创建对象
 *         如果派生类构造函数的成员初始化列表中没有显示调用基类构造函数，
 *         则编译器将使用基类的默认构造函数来构造派生类对象的基类部分
 *      如果定义了某种构造函数，编译器将不会定义默认构造函数。
 *      最好提供一个显示默认构造函数，将所有的类数据成员都初始化为合理的值
 *
 *      2.复制构造函数
 *        复制构造函数接受其所属类的对象作为参数。Star（const Star &）；
 *        在下述情况下，将使用复制构造函数：
 *          将新对象初始化为一个同类对象；
 *          按值将对象传递给函数；
 *          函数按值返回对象；
 *          编译器生成临时对象；
 *        如果程序没有使用复制构造函数，编译器将提供原型，但不提供函数定义；
 *        否则程序将定义一个执行成员初始化的复制构造函数，也就是说，新对象的每个成员都
 *        被初始化为原始对象相应的成员值。
 *        在某些情况下，成员初始化是不合适的。例如，使用new初始化的成员指针通常要执行
 *        深复制，或者类可能需要修改的静态变量。在上述情况下，需要定义自己的复制构造函数
 *
 *     3.赋值运算符
 *       默认的赋值运算符用于处理同类对象之间的赋值。如果语句创建新的对象，则使用初始化。
 *       如果语句修改已有对象的值，则是赋值。
 *
 *   其他要注意的地方
 *      1.构造函数
 *      2.析构函数
 *          一定要定义显示析构函数来释放类构造函数使用new分配的所有内存，并完成类对象所需的任何特殊清理工作
 *          对于基类，即使它不需要析构函数，也应提供一个虚析构函数
 *      3.转换
 *          使用一个参数就可以调用的构造函数定义了从参数类型到类类型的转换
 *
 *          Star(const char*) // converts char* to Star
 *          Star(const Spectral &,int members =-1);// converts Spectral to Star
 *
 *          在带一个参数的构造函数原型中使用explicit将禁止进行隐式转换，但仍允许显示转换
 *
 *     4.按值传递对象与传递引用
 *         通常，编写使用对象作为参数的函数时，应按引用而不是按值来传递对象。
 *         这样做的原因之一是为了提高效率，按值传递对象涉及到生成临时拷贝，即调用复制构造函数，然后调用析构函数。
 *         调用这些函数需要时间，复制大型对象比传递引用花费的时间要多得多。如果函数不修改对象，应该讲参数声明为const引用
 *
 *         按引用传递对象的另外一个原因是，在继承使用虚函数时，被定义为接收基类引用参数的函数可以接收派生类
 *
 *     5.返回对象与返回引用
 *
 *          返回对象涉及到返回对象的临时副本，因此返回对象的时间成本包括调用复制构造函数来生成副本所需的时间
 *          和调用析构函数删除副本所需的时间
 *          返回引用可以节省时间和内存
 *
 *          然而并不是总可以返回引用。函数不能返回在函数中创建临时对象的引用。因为当函数结束时，临时对象将消失，
 *          因此这种引用时非法的，在这种情况下，应返回对象
 *
 *     6.使用const
 *
 *     虚方法：
 *          设计基类时，必须确定是否将类方法声明为虚的。如果希望派生类能够重新定义方法，则应在基类中将方法定义为虚的。
 *        这样可以启用晚期联编（动态联编）；如果不希望重新定义方法，则不必将其声明为虚的，
 *        这样虽然无法禁止他人重新定义方法，但表达了这样的意思；您不希望它被重新定义。
 *
 *        基类的析构函数应该是虚的。
 *
 *     友元函数
 *          由于友元函数并非类成员，因此不能继承。然而您可能希望派生类的友元函数能够使用基类的友元函数
 *
 *     ，为此，可以通过强制类型转换，将派生类引用或指针类型转换为基类引用或指针，然后使用转换后的指针或引用来调用基类的友元函数。
 *
 *
 */
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
