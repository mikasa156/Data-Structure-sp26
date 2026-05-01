//
// Created by yurino on 2026/4/16.
//

#ifndef STACKS_TLINKEDQUEUE_H
#define STACKS_TLINKEDQUEUE_H

#include "../Lists/TLinkedList.h"
#include <vector>


template<typename T>
class TLinkedQueue {
public:
    TLinkedQueue();
    TLinkedQueue(std::vector<T>& arr);
    ~TLinkedQueue();
    void push(T x);
    T pop();
    T peek();
    int size();
    bool isEmpty();
    void print();
private:
    TLinkedList<T> data;
    int size_;
};

#include "TLinkedQueue.tpp"

#endif //STACKS_TLINKEDQUEUE_H
