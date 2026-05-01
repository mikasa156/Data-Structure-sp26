//
// Created by yurino on 2026/4/13.
//

#ifndef STACKS_ARRAYSTACK_H
#define STACKS_ARRAYSTACK_H


const int max_size = 100;
template<typename T>
class ArrayStack {
public:
    ArrayStack();
    ArrayStack(T a[]);
    ~ArrayStack();
    void push(T x);
    T pop();
    T peek();
    bool isEmpty();
    int size();
private:
    T data[max_size];
    int size_;
    int top; // pointer of the stack

};

#include "ArrayStack.tpp"

#endif //STACKS_ARRAYSTACK_H
