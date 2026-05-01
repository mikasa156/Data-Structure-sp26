# Chapter 3

## q2

![image-20260415150839107](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260415150839107.png)

```
1 -> 1-3 -> 3 -> 3-5 -> 3-5-7 -> 5-7 -> 5-7-9
```

因此队首和队尾元素分别是**5**和**9**

![image-20260415151221127](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260415151221127.png)

非法操作只有当栈为空时出栈

1. 合法，进行所有的出栈操作时栈都不为空
2. 不合法。开头的“IOO”先进栈一次，后出栈两次。第二次出栈时栈为空了，不合法。
3. 不合法。总共进栈5次，出栈3次，虽然每次出栈都是合法的，但最后栈内会剩余两个元素，栈不为空，故不合法。
4. 合法。

## q3

#### (1)

![image-20260415152010578](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260415152010578.png)

**基本思路**：教材版本的循环链表`tail`指针不指向哨兵节点，其本身指向尾节点，`tail.next`指向首节点。因此可有如下逻辑：

- **入队**：当tail为nullptr时，直接对tail赋值即可。当tail不为nullptr时，先构建临时节点tmp_node，将tail后继设为tmp_node，最后更新tail为tmp_node。
  - 复杂度：$O(1)$
- **出队**：1. queue为空，报错。2. queue长度为1，弹出tail即可。3. 否则，构建临时节点指向head节点，让tail的后继指向head的后继，删除临时节点。
  - 复杂度：$O(1)$

**伪代码**

```cpp
template<typename T>
void push(T x) {
    if (tail == nullptr) {
        tail = new Node(x, nullptr);
        tail->next = tail;
    } else {
        Node* tmp_node = new Node(x, tail->next);
        tail->next = tmp_node;
        tail = tmp_node;
    }
	size_++;
}

template<typename T>
T pop() {
    if (size_ == 0) { // the size of queue
        throw std::runtime_error("Queue is empty.");
    }
    if (size_ == 1) {
        Node* tmp = tail;
        T val = tail->data;
        tail = nullptr;
        delete tmp;
        size_--;
        return val;
    }
    Node* tmp = tail->next;
    T val = tmp->data;
    tail->next = tail->next->next;
    delete tmp;
    size_--;
	return val;
}
```

**代码**：核心代码如上，相关代码在`..\Stacks\TLinkedQueue`中，其中核心逻辑封装在`..\Lists\TLinkedList`的`T removeFirst()`和`void addLast(T x)`中。这里给出test代码及结果。

```cpp
#include "../Stacks/TLinkedQueue.h"

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
```

运行结果如下：

![image-20260417101010027](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260417101010027.png)



#### (3)

![image-20260416134544850](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260416134544850.png)

**基本思路**：十进制转换为二进制到九进制的基本思路是做除法，有如下除法公式：

> 十进制数 / base = 商...余数

不断将十进制数做除法，得到余数列，按照最后一个余数到第一个余数逆序输出就得到了对应的p进制数，这正好符合栈LIFO的特性。

*算法*：当数num不为0时，计算除进制p的**商**和**余数**，将余数压进栈，更新num为商，最后不断从栈中取栈顶元素即可。

- 边界情况，当`num == 0`，直接返回0。当`num < 0`，应先将num取负，这样才能正确取模和做整数除法。

*注：对于负数的情况没有采取补码的操作，而是直接用负号表示*

**伪代码**

```cpp
std::string dec_2_base(int num, int base) {
    std::stack<int> p_num;
    std::string ans;
    if (num == 0) {
        // edge situation
        std::cout << "0" << std::endl;
        return "0";
    }
    if (num < 0) {
        ans = "-";
        num = -num;
    }
    while (num != 0) {
        int quotient = num / base;
        int remainder = num % base;
        p_num.push(remainder);
        num = quotient;
    }
    while (!p_num.empty()) {
        int top = p_num.top();
        p_num.pop();
        ans += std::to_string(top);
    }
    std::cout << ans << std::endl;
    return ans;
} 

```

**代码**：

```cpp
#include <stack>
#include <string>
#include <iostream>

// almost same as above, we omitted the definition here for simplicity
std::string dec_2_base(int num, int base); 

int main() {
    dec_2_base(5, 2);
    dec_2_base(10, 10);
    dec_2_base(100,9);
    dec_2_base(89, 7);
    dec_2_base(-58, 8);
    dec_2_base(0, 9);
    return 0;
}

```

运行结果如下，经检查是正确的：

![image-20260417153133417](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260417153133417.png)

#### (4)

![image-20260417153206057](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260417153206057.png)

**基本思路**：初始化front和rear都为0，flag为0。

- **push**：入队逻辑基本和教材一致。当入队后`front == rear`，说明队满，更新flag为1
- **pop**：出队一样，基本逻辑和教材一致。注意出队则队列一定不为空，更新flag为0

**伪代码**

```cpp
void push(T x) {
    if (isFull()) {
        throw std::overflow_error("Queue is full.");
    }
    rear = (rear + 1) % max_size;
    data[rear] = x;
    if (front == rear) {
        flag = 1;
    }
}

void pop() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty.");
    }
    front = (front + 1) % max_size;
    flag = 0;
}
```

**代码**：相关逻辑实现在`"..\Queues\CirQueue.tpp"`中，这里给出test code

```cpp
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

```

运行结果如下：

![image-20260417174046102](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260417174046102.png)
