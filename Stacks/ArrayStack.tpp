//
// Created by yurino on 2026/4/13.
//

#include "ArrayStack.h"

template <typename T>
ArrayStack<T>::ArrayStack() {
    top = -1;
    size_ = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(T a[]) {
    int size_a = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size_a; i++) {
        data[i] = a[i];
    }
    top = -1;
    size_ = size_a;
}

template <typename T>
int ArrayStack<T>::size() {
    return size_;
}

template <typename T>
bool ArrayStack<T>::isEmpty() {
    return top == 0;
}

template <typename T>
void ArrayStack<T>::push(T x) {
    if (top + 1 == max_size) {
        throw "overflow";
    }
    data[top++] = x;
    size_++;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    top = -1;
    size_ = 0;
}

template <typename T>
T ArrayStack<T>::pop() {
    if (top = -1) {
        throw "empty";
    }
    top = top - 1;
    return data[top + 1];
}

template <typename T>
T ArrayStack<T>::peek() {
    return data[top];
}
