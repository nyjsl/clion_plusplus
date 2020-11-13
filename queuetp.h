
//
// Created by xiaolian on 2020/11/13.
//

#ifndef CLION_CPLUSPLUS_QUEUETP_H
#define CLION_CPLUSPLUS_QUEUETP_H
template <class Item>
class QueueTP{
private:
    enum{Q_SIZE = 10};
    class Node{
    public:
        Item item;
        Node * next;
        Node(const Item & i):item(i),next(0){}
    };

    Node * front;
    Node * rear;
    int items;
    const int qsize;
    QueueTP(const QueueTP & q):qsize(0){}
    QueueTP & operator=(const QueueTP & q){
        return *this;
    }

public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const{
        return items == 0;
    }

    bool isFull() const{
        return items == qsize;
    }

    int queuecount() const{
        return items;
    }

    bool euqueue(const Item & item);
    bool dequeue(Item & item);
};

template<class Item>
QueueTP<Item>::QueueTP(int qs):qsize(qs) {
    front = rear = 0;
    items = 0;
}

template<class Item>
QueueTP<Item>::~QueueTP() {
    Node * temp;
    while (front != 0) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<class Item>
bool QueueTP<Item>::euqueue(const Item &item) {
    if (isFull()) {
        return false;
    }
    Node * add = new Node(item);
    items++;
    if (front == 0) {
        front = add;
    }else{
        rear->next = add;
    }
    rear = add;
    return true;
}

template<class Item>
bool QueueTP<Item>::dequeue(Item &item) {
    if (front == 0) {
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0) {
        rear = 0;
    }
    return true;
}


#endif //CLION_CPLUSPLUS_QUEUETP_H
