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
SLList<T>::SLList(T a[], int n) : SLList() {
    for (int i = 0; i < n; i++) {
        add(i, a[i]);
    }
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
    return (sentinel->next == nullptr || size_ == 0);
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
    if (index < 0 || index > size_) {
        throw "invalid index";
    }
    Node* p = sentinel;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    Node* tmp_node = new Node(val, nullptr);
    Node* p_next = p->next;
    p->next = tmp_node;
    p->next->next = p_next;
    size_++;
}

template<typename T>
void SLList<T>::addLast(T val) {
    Node* p = sentinel;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new Node(val, nullptr);
    size_++;
}

template<typename T>
void SLList<T>::addFirst(T val) {
    Node* tmp = new Node(val, sentinel->next);
    sentinel->next = tmp;
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
    Node* to_delete = p->next;
    T tmp = to_delete->data;
    p->next = to_delete->next;
    delete to_delete;
    size_--;
    return tmp;
}

template<typename T>
T SLList<T>::removeFirst() {
    if (empty()) {
        throw "empty linked list";
    }
    Node* to_delete = sentinel->next;
    T tmp = to_delete->data;
    sentinel->next = to_delete->next;
    delete to_delete;
    size_--;
    return tmp;
}

template<typename T>
T SLList<T>::removeLast() {
    if (empty()) {
        throw "empty linked list";
    }
    Node* p = sentinel;
    while (p->next->next != nullptr) {
        p = p->next;
    }
    Node* to_delete = p->next;
    T tmp = to_delete->data;
    p->next = to_delete->next;
    delete to_delete;
    size_--;
    return tmp;
}

template<typename T>
T SLList<T>::getLast() {
    if (empty()) {
        throw "empty linked list";
    }
    Node* p = sentinel->next;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p->data;
}

template<typename T>
void SLList<T>::print() {
    Node* p = sentinel;
    for (int i = 0; i < size_ - 1; i++) {
        p = p->next;
        std::cout << p->data << "->";
    }
    p = p->next;
    std::cout << p->data << '\n';
}

template<typename T>
void SLList<T>::reverse() {
    Node* prev = nullptr;
    Node* curr = sentinel->next;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    sentinel->next = prev;
}

template<typename T>
void SLList<T>::increase() {
    while (sentinel->next != nullptr) {
        Node* prev = sentinel; // prev node of minNode
        Node* curr = sentinel;
        while (curr->next != nullptr) {
            if (curr->next->data < prev->next->data) {
                prev = curr;
            }
            curr = curr->next;
        }
        Node* minNode = prev->next;
        prev->next = prev->next->next;
        std::cout << minNode->data << " ";
        delete minNode;
        size_--;
    }
    std::cout << '\n';
}

template<typename T>
void SLList<T>::delRedundant() {
    if (sentinel->next == nullptr) {
        return;
    }
    Node* left = sentinel->next;
    Node* right = sentinel->next->next;
    while (right != nullptr) {
        if (right->data != left->data) {
            left->next = right;
            left = right;
            right = right->next;
            continue;
        }
        Node* tmp = right;
        right = right->next;
        delete tmp;
        size_--;
    }
    left->next = nullptr;
}
