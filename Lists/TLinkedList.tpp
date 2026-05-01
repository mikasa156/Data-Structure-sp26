//
// Created by yurino on 2026/4/16.
//

#include "TLinkedList.h"

#include <stdexcept>
#include <iostream>

// remember to change the tail pointer!!!

template <typename T>
TLinkedList<T>::TLinkedList() {
    tail = nullptr;
    size_ = 0;
}

template <typename T>
TLinkedList<T>::~TLinkedList() {
    if (tail == nullptr) {
        return;
    }
    Node* head = tail->next;
    Node* p = head;
    do {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    } while (p != head);
    tail = nullptr;
    size_ = 0;
}

template <typename T>
void TLinkedList<T>::addFirst(T x) {
    if (tail == nullptr) {
        tail = new Node(x, nullptr);
        tail->next = tail;
        size_++;
        return;
    }
    Node* tmp = new Node(x, tail->next);
    tail->next = tmp;
    size_++;
}

template <typename T>
void TLinkedList<T>::addLast(T x) {
    if (tail == nullptr) {
        tail = new Node(x, nullptr);
        tail->next = tail;
        size_++;
        return;
    }
    Node* tmp = new Node(x, tail->next);
    tail->next = tmp;
    tail = tmp;
    size_++;
}

template <typename T>
T TLinkedList<T>::removeFirst() {
    if (size_ == 0) {
        throw std::runtime_error("LinkedList is empty");
    }
    if (size_ == 1) {
        Node* tmp = tail;
        T val = tail->data;
        tail = nullptr;
        delete tmp;
        size_--;
        return val;
    }
    Node* tmp = tail->next;
    T val = tmp->data;
    tail->next = tail->next->next;
    delete tmp;
    size_--;
    return val;
}

template <typename T>
T TLinkedList<T>::removeLast() {
    if (size_ == 0) {
        throw std::runtime_error("Queue is empty");
    }
    if (size_ == 1) {
        Node* tmp = tail;
        T val = tail->data;
        tail = nullptr;
        delete tmp;
        size_--;
        return val;
    }
    Node* p = tail->next;
    while (p->next != tail) {
        p = p->next;
    }
    T val = tail->data;
    p->next = tail->next;
    delete tail;
    tail = p;
    size_--;
    return val;
}

template <typename T>
bool TLinkedList<T>::isEmpty() {
    return size_ == 0;
}

template <typename T>
int TLinkedList<T>::size() {
    return size_;
}

template <typename T>
void TLinkedList<T>::print() {
    if (size_ == 0) {
        std::cout << "" << std::endl;
        return;
    }

    Node* p = tail;
    while (p->next != tail) {
        p = p->next;
        std::cout << p->data << "->";
    }
    p = p->next;
    std::cout << p->data << std::endl;
}
