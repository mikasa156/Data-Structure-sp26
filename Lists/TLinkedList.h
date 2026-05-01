//
// Created by yurino on 2026/4/16.
//

#ifndef LISTS_TLINKEDLIST_H
#define LISTS_TLINKEDLIST_H


template<typename T>
class TLinkedList {
public:
    TLinkedList();
    ~TLinkedList();
    int size();
    bool isEmpty();
    void addFirst(T x);
    void addLast(T x);
    T removeLast();
    T removeFirst();
    void print();

private:
    int size_;
    class Node {
    public:
        Node(const T& val, Node* next = nullptr)
            :data(val), next(next) {}
        T data;
        Node* next;
    };
    Node* tail;
};


#include "TLinkedList.tpp"


#endif //LISTS_TLINKEDLIST_H
