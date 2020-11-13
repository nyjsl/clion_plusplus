//
// Created by xiaolian on 2020/11/13.
//

#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class HasFriend{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i): item(i){ct++;}
    ~HasFriend(){ct--;}
    friend void counts();
    friend void reports(HasFriend<T> &);

//template parameter
};

template<typename T>
int HasFriend<T> ::ct = 0;
void counts() {
    cout << " int count: " << HasFriend<int>::ct << endl;
    cout << " double count: " << HasFriend<double>::ct << endl;
}

 void reports(HasFriend<int> & hf) {
    cout << " HasFriend<int>: " << hf.item << endl;
}
void reports(HasFriend<double> & hf){
    cout << " HasFriend<double>: " << hf.item << endl;
}

int main(){
    cout << "No objects declared: ";
    counts();
    HasFriend<int> hfi(10);
    cout << "After hfi declared: ";
    counts();
    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();
    reports(hfi);
    reports(hfi2);
    reports(hfdb);
    return 0;
}

