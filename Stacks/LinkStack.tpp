//
// Created by yurino on 2026/4/13.
//

#include "LinkStack.h"

template <typename T>
LinkStack<T>::LinkStack(T a[]) {
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        data.add(a[i]);
    }
}

template <typename T>
void LinkStack<T>::push(T x) {
    data.add(x);
}

template <typename T>
T LinkStack<T>::pop() {
    T tmp = data.removeLast();
    return tmp;
}

template <typename T>
T LinkStack<T>::peek() {
    return data.getLast();
}

template <typename T>
bool LinkStack<T>::isEmpty() {
    return data.empty();
}

template <typename T>
int LinkStack<T>::size() {
    return data.size();
}


