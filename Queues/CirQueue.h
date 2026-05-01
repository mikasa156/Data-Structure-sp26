//
// Created by yurino on 2026/4/17.
//

#ifndef QUEUES_SEQQUEUE_H
#define QUEUES_SEQQUEUE_H

#include <vector>
#include <iostream>

const int max_size = 5;

template<typename T>
class CirQueue {
public:
    CirQueue();
    CirQueue(std::vector<T> vec);
    ~CirQueue();
    void push(T x);
    void pop();
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
    void print();


private:
    T* data;
    int size_;
    int head;
    int tail;
    short flag;
};

#include "CirQueue.tpp"

#endif //QUEUES_SEQQUEUE_H
