//
// Created by 22172 on 2026/3/29.
//

#ifndef DATA_STRUCTURE_SP26_SLLIST_H
#define DATA_STRUCTURE_SP26_SLLIST_H

template<typename T>
class SLList {
private:
    class Node {
    public:
        Node(const T& d, Node* n = nullptr)
            :data(d), next(n) {}
        T data;
        Node* next;
    };
    Node* sentinel;
    int size_;

public:
    SLList();
    SLList(T a[], int n);
    ~SLList();
    int size();
    T get(int i);
    int locate(T val);
    void add(int index, T val);
    T remove(int i);
    bool empty();

    // hw functions
    void print();
    void increase();
    void delRedundant();


    void addLast(T val);
    void addFirst(T val);
    T removeFirst();
    T removeLast();

    T getLast();
    void reverse();
};

#include "SLList.tpp"
#endif //DATA_STRUCTURE_SP26_SLLIST_H
