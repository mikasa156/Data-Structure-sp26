//
// Created by yurino on 2026/4/16.
//

#include "TLinkedQueue.h"

template<typename T>
TLinkedQueue<T>::TLinkedQueue() {
    size_ = 0;
}

template <typename T>
TLinkedQueue<T>::TLinkedQueue(std::vector<T>& arr) {
    size_ = 0;
    for (int i = 0; i < arr.size(); i++) {
        data.addLast(arr[i]);
        size_++;
    }
}

template<typename T>
TLinkedQueue<T>::~TLinkedQueue() {
    size_ = 0;
}

template <typename T>
void TLinkedQueue<T>::push(T x) {
    data.addLast(x);
    size_++;
}

template <typename T>
T TLinkedQueue<T>::pop() {
    if (size_ == 0) {
        throw "empty";
    }
    T tmp = data.removeFirst();
    size_--;
    return tmp;
}

template <typename T>
T TLinkedQueue<T>::peek() {
    if (size_ == 0) {
        throw "empty";
    }
    return data.getFirst();
}

template <typename T>
int TLinkedQueue<T>::size() {
    return size_;
}

template <typename T>
bool TLinkedQueue<T>::isEmpty() {
    return size_ == 0;
}

template <typename T>
void TLinkedQueue<T>::print() {
    data.print();
}


