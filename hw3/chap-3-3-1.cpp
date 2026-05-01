//
// Created by yurino on 2026/4/16.
//

#include "../Queues/TLinkedQueue.h"

int main() {
    std::vector<int> arr {1, 2, 3, 4, 5};
    TLinkedQueue<int> queue(arr);
    queue.print();

    queue.push(6);
    queue.push(7);

    queue.print();

    queue.pop();
    queue.pop();

    queue.print();
    return 0;
}
