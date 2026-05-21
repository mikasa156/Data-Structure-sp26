#include <iostream>
#include "../Trees/BST.h"

int main() {
    std::vector<int> data1 {3, 2, 2, 5, 8, 1};
    BST<int> bst1(data1);

    std::vector<int> data2 {};
    BST<int> bst2(data2);

    std::vector<int> data3 {3, 2, 2, 5, 8, 1};
    BST<int> bst3(data3);

    bst1.print();
    bst1.deleteX(2);
    bst1.print();

    bst2.print();
    bst2.deleteX(2);
    bst2.print();

    bst3.print();
    bst3.deleteX(7);
    bst3.print();

    return 0;
}
