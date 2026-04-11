//
// Created by 22172 on 2026/4/1.
//
#include "../Lists/SLList.h"
#include "../Lists/SeqList.h"

int main() {
    int a[5]{1, 2, 3, 4, 5};
    SeqList<int> s(a, 5);
    s.reverse();
    s.print();

    SLList<int> sl_list(a, 5);
    sl_list.reverse();
    sl_list.print();
    return 0;
}