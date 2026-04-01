//
// Created by 22172 on 2026/4/1.
//

#include "../List/SeqList.h"

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[10] = {0, 1, 0, 1, 1, 0, 0, 1, 0, 1};
    SeqList<int> s1(a, 5);
    SeqList<int> s2(b, 10);
    s1.print();
    s1.removeX(3);
    s1.print();
    s1.removeX(6);
    s1.print();
    s2.print();
    s2.removeX(0);
    s2.print();
    s2.removeX(1);
    s2.print();
    return 0;
}