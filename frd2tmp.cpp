//
// Created by xiaolian on 2020/11/13.
//

#include <iostream>
using std::cout;
using std::endl;

// template prototype
template <typename T> void counts();

template<typename T> void reports(T &);


template<typename TT>
class HasFriend{
private:
    TT item;
    static int ct;
public:
    HasFriend(const TT & i): item(i){ct++;}
    ~HasFriend(){ct--;}
    friend void counts<TT>();
    //编译器可以从参数类型推断出要使用的具体化,使用<>格式也能获得同样的效果
    friend void reports<>(HasFriend<TT> &);

//template parameter
};

template<typename T>
int HasFriend<T> ::ct = 0;
template <typename T>
void counts() {
    cout << " templatesize" << sizeof(HasFriend<T>)<< endl;
    cout << " template count: " << HasFriend<T>::ct << endl;
}


template <typename T>
 void reports(T & hf) {
    cout << hf.item << endl;
}

//int main(){
//    counts<int>();
//    HasFriend<int> hfi1(10);
//    HasFriend<int> hfi2(20);
//    HasFriend<double> hfdb(10.5);
//    reports(hfi1);
//    reports(hfi2);
//    reports(hfdb);
//    cout << " counts<int> output:\n";
//    counts<int>();
//    cout << " counts<double> output:\n";
//    counts<double>();
//    return 0;
//}

