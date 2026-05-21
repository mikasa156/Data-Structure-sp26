#include "BST.h"
#include <iostream>

int main() {
    BST<int> t;
    for (int v : {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15}) {
        t.add(v);
    }
    std::cout << "size=" << t.size() << "\n\n";
    t.print();
    return 0;
}

