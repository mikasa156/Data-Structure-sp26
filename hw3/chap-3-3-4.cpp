#include "../Queues/CirQueue.h"

int main() {
    std::vector<int> v {1, 2, 3, 4};
    CirQueue<int> cqueue(v);
    cqueue.print();

    cqueue.push(5);
    cqueue.print();

    cqueue.pop();
    cqueue.print();

    cqueue.push(6);
    cqueue.print();

    cqueue.push(7);
    
    return 0;
}
