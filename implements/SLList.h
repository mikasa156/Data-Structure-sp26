//
// Created by 22172 on 2026/3/29.
//

#ifndef DATA_STRUCTURE_SP26_SLLIST_H
#define DATA_STRUCTURE_SP26_SLLIST_H

template<typename T>
class SLList {
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
    void print();

    void addLast(T val);
    void addFirst(T val);
    void removeFirst();
    void removeLast();


private:
    class Node {
    public:
        Node(const T& d, Node* n = nullptr)
            :data(d), next(n) {}
    private:
        T data;
        Node* next;
    };
    Node sentinel;
    int size_;
};


#endif //DATA_STRUCTURE_SP26_SLLIST_H