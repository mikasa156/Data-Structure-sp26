#include <iostream>
#include <vector>
#include "../Trees/BST.h"

int main() {
    std::vector<int> vec {3, 2, 8, 5, 0, 8};
    BST<int> bst(vec);

    bst.print();
    bst.exchange();
    bst.print();

    return 0;
}
