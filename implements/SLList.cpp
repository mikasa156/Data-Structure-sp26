//
// Created by 22172 on 2026/3/29.
//

#include "SLList.h"
#include <iostream>

template<typename T>
SLList<T>::SLList() {
    sentinel = new Node(T(), nullptr);
    size_ = 0;
}

template<typename T>
SLList<T>::SLList(T a[], int n) {
    SLList();
    for (int i = 0; i < n; i++) {

    }
    size_ = n;
}

template<typename T>
SLList<T>::~SLList() {
    Node* p = sentinel;
    while (p != nullptr) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

template<typename T>
int SLList<T>::size() {
    return size_;
}

template<typename T>
bool SLList<T>::empty() {
    return size_ == 0;
}

template<typename T>
T SLList<T>::get(int index) {
    if (index >= size_ || index < 0) {
        throw "invalid index";
    }
    Node* p = sentinel;
    for (int i = 0; i <= index; i++) {
        p = p->next;
    }
    return p->data;
}

// linkedlist要locate干嘛？
template<typename T>
int SLList<T>::locate(T val) {
    Node* p = sentinel;
    for (int i = 0; i < size_; i++) {
        p = p->next;
        if (p->data == val) {
            return i;
        }
    }
    return -1;
}

// why should we implement a O(n) insert?
template<typename T>
void SLList<T>::add(int index, T val) {
    // after index, that is:
    // index - newNode - index + 1
    if (index < 0 || index >= size_) {
        throw "invalid index";
    }
    Node* p = sentinel;
    for (int i = 0; i <= index; i++) {
        p = p->next;
    }
    Node* tmp_node = new Node(val, nullptr);
    Node* p_next = p->next;
    p->next = tmp_node;
    p->next->next = p_next;
    size_++;
}

template<typename T>
T SLList<T>::remove(int i) {
    if (empty()) {
        throw "empty linked list";
    }
    if (i < 0 || i >= size_) {
        throw "invalid index";
    }
    Node* p = sentinel;
    // 只访问到前序节点 j < i
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    T tmp = p->next->data;
    p->next = p->next->next;
    size_--;
    return tmp;
}

template<typename T>
void SLList<T>::print() {
    Node* p = sentinel;
    while (p->next != nullptr) {
        p = p->next;
        std::cout << p->data << "->";
    }
}
