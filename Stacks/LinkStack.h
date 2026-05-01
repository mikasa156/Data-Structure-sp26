//
// Created by yurino on 2026/4/13.
//
#include "../Lists/SLList.h"

#ifndef STACKS_LINKSTACK_H
#define STACKS_LINKSTACK_H

template<typename T>
class LinkStack {
private:
    SLList<T> data;
    int size_;
public:
    LinkStack(T a[]);
    //~LinkStack();
    void push(T x);
    T pop();
    T peek();
    int size();
    bool isEmpty();

};



#endif //STACKS_LINKSTACK_H
