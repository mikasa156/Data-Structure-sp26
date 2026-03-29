//
// Created by 22172 on 2026/3/29.
//

#include "SeqList.h"
#include <iostream>

template<typename T>
SeqList<T>::SeqList() {
    size_ = 0;
}

template<typename T>
SeqList<T>::SeqList(T a[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    size_ = n;
}

template<typename T>
SeqList<T>::~SeqList() {
    size_ = 0;
}

template<typename T>
int SeqList<T>::size() {
    return size_;
}

template<typename T>
bool SeqList<T>::empty() {
    return size_ == 0;
}

template<typename T>
T SeqList<T>::get(int i) {
    if (i < 0 || i >= size_) {
        throw "invalid index";
    }
    return data[i];
}

template<typename T>
int SeqList<T>::locate(int v) {
    for (int i = 0; i < size_; i++) {
        if (data[i] == v) {
            return i;
        }
    }
    return -1;
}


template<typename T>
void SeqList<T>::add(int i, T x) {
    if (size_ == maxSize) {
        throw "overflow";
    }
    // can be added at size_ (tail position)
    if (i < 0 || i > size_) {
        throw "invalid index";
    }
    for (int j = size_; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = x;
    size_++;
}

template<typename T>
T SeqList<T>::remove(int i) {
    if (empty()) {
        throw "empty list";
    }
    if (i < 0 || i >= maxSize) {
        throw "invalid index";
    }
    T tmp = data[i];
    for (int j = i; j < size_ - 1; j++) {
        data[j] = data[j + 1];
    }
    size_--;
    return tmp;
}

template<typename T>
void SeqList<T>::print() {
    for (int i = 0; i < size_; i++) {
        std::cout << data[i] << " ";
    }
}



