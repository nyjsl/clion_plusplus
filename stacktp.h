//
// Created by xiaolian on 2020/11/12.
//

#ifndef CLION_CPLUSPLUS_STACKTP_H
#define CLION_CPLUSPLUS_STACKTP_H

template <class Type>
class Stack{
private:
    enum {MAX = 10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isEmpty();
    bool isFull();
    bool push(const Type & item);
    bool pop(Type &item);
};

template<class Type>
Stack<Type>::Stack() {
    top = 0;
}

template<class Type>
bool Stack<Type>::isEmpty() {
    return top == 0;
}

template<class Type>
bool Stack<Type>::isFull() {
    return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    }
    return false;
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if(top>0){
        item = items[--top];
        return true;
    }
    return false;
}

#endif //CLION_CPLUSPLUS_STACKTP_H
