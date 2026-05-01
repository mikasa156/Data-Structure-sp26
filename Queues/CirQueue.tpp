//
// Created by yurino on 2026/4/17.
//

#include <ostream>

#include "CirQueue.h"

template <typename T>
CirQueue<T>::CirQueue() {
    size_ = 0;
    data = new T[max_size];
    head = 0; tail = 0; flag = 0;
}

template <typename T>
CirQueue<T>::CirQueue(std::vector<T> vec) {
    size_ = 0;
    data = new T[max_size];
    head = 0; tail = 0; flag = 0;
    for (const auto& item : vec) {
        push(item);
    }
}

template <typename T>
CirQueue<T>::~CirQueue() {
    delete[] data;
}

template <typename T>
bool CirQueue<T>::isEmpty() {
    return head == tail && !flag;
}

template <typename T>
bool CirQueue<T>::isFull() {
    return head == tail && flag;
}

template <typename T>
void CirQueue<T>::push(T x) {
    if (isFull()) {
        throw std::overflow_error("Queue is full.");
    }
    tail = (tail + 1) % max_size;
    data[tail] = x;
    if (head == tail) {
        flag = 1;
    }
    size_++;
}

template <typename T>
void CirQueue<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty.");
    }
    head = (head + 1) % max_size;
    flag = 0;
    size_--;
}

template <typename T>
int CirQueue<T>::size() {
    if (isFull()) {
        return max_size;
    }
    return (head - tail + max_size) % max_size;
}

template <typename T>
T CirQueue<T>::peek() {
    if (isEmpty()) {
        throw "Queue is empty.";
    }
    return data[(head + 1) % max_size];
}

template <typename T>
void CirQueue<T>::print() {
    if (isEmpty()) {
        std::cout << " " << std::endl;
        return;
    }
    int p = head;
    while ((p + 1) % max_size != tail) {
        p = p + 1;
        std::cout << data[p % max_size] << " ";
    }
    std::cout << data[(p + 1) % max_size] << std::endl;
}
