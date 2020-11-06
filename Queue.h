//
// Created by xiaolian on 2020/11/6.
//

#ifndef CLION_CPLUSPLUS_QUEUE_H
#define CLION_CPLUSPLUS_QUEUE_H

class Customer{
private:
    long arrive;
    int processtime;
public:
    Customer(){
        arrive = processtime = 0;
    }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue{
private:
    struct Node{
        Item item;
        struct Node * next;
    };
    enum {Q_SIZE = 10};
    Node * front; //pointer to front of Queue
    Node * rear;  //pointer to rear of Queu
    int items;
    const int qsize;
    //preemptive definitions to prevent public copying
    Queue(const Queue & q):qsize(0){}
    Queue &operator=(const Queue &queue){ return *this; }

public:

    Queue(int qs = Q_SIZE);

    Queue();

    ~Queue();
    bool isEmpyt() const;
    bool isFull() const;
    int queuecount() const;

    bool enqueue(const Item &item);

    bool dequeue(Item &item);

};

#endif //CLION_CPLUSPLUS_QUEUE_H
