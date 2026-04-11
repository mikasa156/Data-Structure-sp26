//
// Created by 22172 on 2026/4/1.
//

#include "../Lists/SLList.h"

int main() {
    int a[13] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6};
    SLList<int> s(a, 13);
    s.print();
    s.delRedundant();
    s.print();
    return 0;
}