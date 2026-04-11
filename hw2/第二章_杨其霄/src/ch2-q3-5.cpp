//
// Created by 22172 on 2026/4/1.
//

#include "../Lists/SLList.h"

int main() {
    int a[10] = {3, 4, 4, 2, 1, 7, 8, 20, 15, 0};
    SLList<int> s(a, 10);
    s.print();
    s.increase();
    std::cout << "isEmpty: " << s.empty();
    return 0;
}