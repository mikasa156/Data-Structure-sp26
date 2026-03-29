//
// Created by 22172 on 2026/3/29.
//

#ifndef DATA_STRUCTURE_SP26_SEQLIST_H
#define DATA_STRUCTURE_SP26_SEQLIST_H

const int maxSize = 100;
template <typename T>
class SeqList {
public:
    SeqList();
    SeqList(T a[], int n);
    ~SeqList();

    int size();
    T get(int i);
    int locate(int i);
    void add(int i, T x);
    T remove(int i);
    bool empty();
    void print();

private:
    T data[maxSize];
    int size_;
};


#endif //DATA_STRUCTURE_SP26_SEQLIST_H