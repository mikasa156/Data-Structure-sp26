# Data Structure hw2



## Q3

### (2) 

![image-20260401153724979](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401153724979.png)

> *补：平均时间复杂度O(n)*

#### 基本思路

关键在于将删除元素之后的元素进行前移，“删除”完之后再逐个前移会导致$O(n^2)$的复杂度，因此我们考虑交换元素而非单独的搬移。

注意到这道题可以用双指针解决，我们基本的思路就是维护两个指针`right`和`left`，左指针指向处理好的序列尾部，右指针指向待处理序列的头部，均初始化为0。右指针不断向右移动，每次遇到非x，就将左右指针对应的数交换，同时左指针右移。由于左指针左边均非x，右指针左边直到左指针都是x，因此每次交换都是将左指针的x和右指针的非x交换。

题目要求O(1)空间复杂度则不考虑缩容操作，交换完成之后直接将length减去x的数量即可，末尾的一堆x不会影响顺序表之后的基本操作。

**复杂度**：算法只遍历了一遍数组，swap操作是O(1)的，总的复杂度就是$O(n)$

#### 伪代码

```cpp
void swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
}

void removeX(T x) {
    // data and length are attributes of SeqList
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < length) {
        if (data[right] != x) {
			swap(data[left], data[right]);
            left++;
            count++;
        }
        right++;
    }
    length = count;
}
```

#### 代码

关键部分同上，这里给出test代码。

```cpp
#include "../Lists/SeqList.h"

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[10] = {0, 1, 0, 1, 1, 0, 0, 1, 0, 1};
    SeqList<int> s1(a, 5);
    SeqList<int> s2(b, 10);
    s1.print();
    s1.removeX(3); // remove 3 from s1
    s1.print();
    s1.removeX(6); // remove 6 from s1
    s1.print();
    s2.print();
    s2.removeX(0); // remove 0 from s2
    s2.print();
    s2.removeX(1); // remove 1 from s2
    s2.print();
    return 0;
}
```

输出：

![image-20260401171210595](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401171210595.png)

### (3)

![image-20260401171620836](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401171620836.png)

#### 基本思路

对于顺序表，直接维护两个指针`left`和`right`，当`left < right`的时候交换元素即可。对于链表，遍历所有节点，将当前节点的next置为上一节点即可。由于是单链表，需要额外维护一个`prev`指针。

**复杂度**：都只需要遍历一遍容器，都是$O(n)$

#### 伪代码

```cpp
/** 
 * reverse of SeqList
 */
void reverse() {
    int left = 0;
    int right = length - 1;
    while (left < right) {
        swap(data[left], data[right]);
        left++;
        right--;
    }
}
```

```cpp
/** 
 * reverse of SLList
 * could use recuisive instead.
 */
void reverse() {
    Node* prev = nullptr;
    Node* curr = sentinel->next;
    while (curr != nullptr) {
        Node* next = curr->next; // tmp node
        curr->next = prev; // change curr's next to prev
        prev = curr; // now curr is the 'old' node
        curr = next; // curr = curr->next
    }
    sentinel->next = prev; 
}
```

#### 代码

关键代码如上，test代码：

```cpp
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
```

结果：

![image-20260401175310294](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401175310294.png)

### (5)

![image-20260401183635190](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401183635190.png)

#### 基本思路

维护两个指针`prev`和`curr`，分别指向最小节点的前置节点和当前节点。遍历链表，当`curr->next`值小于`prev->next`值时，更新`prev = curr`。最后用`minNode = prev->next`暂存最小节点，前置节点链接到`minNode`的下一节点，输出值并删除`minNode`即可。

**复杂度**：依次遍历至多n, n-1, ... 1个节点，复杂度$O(n^2)$

#### 伪代码

```cpp
while (sentinel->next != nullptr) {
    // when SLList is not empty
    Node* prev = sentinel; // prev node of minNode
    Node* curr = sentinel;
    while (curr->next != nullptr) {
        if (curr->next->data < prev->next->data) {
            prev = curr;
        }
        curr = curr->next;
    }
    Node* minNode = prev->next; // minNode is the next node of prev
    prev->next = prev->next->next; 
    std::cout << minNode->data << " ";
    delete minNode;
    size_--;
}
```

#### 代码

关键代码如上，test代码：

```cpp
#include "../Lists/SLList.h"

int main() {
    int a[10] = {3, 4, 4, 2, 1, 7, 8, 20, 15, 0};
    SLList<int> s(a, 10);
    s.print();
    s.increase();
    std::cout << "isEmpty: " << s.empty();
    return 0;
}
```

结果：

![image-20260401194309184](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401194309184.png)

### (6)

![image-20260401194351480](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401194351480.png)

#### 基本思路

和3-2的思路基本一致，利用双指针`left`和`right`滑动窗口，左指针是已经两两互异的节点的末节点，右指针左边直到左指针值都相同。

当左右指针`data`不同时，`left->next = right`，并更新`left = right`；

相同时，先用临时指针暂存右指针，右指针更新为下一元素后删除临时指针；

最后断尾，将左指针下一节点设为`nullptr`。

**复杂度**：只用遍历一遍链表，复杂度$O(n)$

#### 伪代码

```cpp
void delRedunant() {
    if (sentinel->next == nullptr) {
        return;
    }
    Node* left = sentinel->next;
    Node* right = sentinel->next->next;
    while (right != nullptr) {
        if (right->data != left->data) {
            left->next = right;
            left = right;
            right = right->next;
            continue;
        }
        Node* tmp = right;
        right = right->next;
        delete tmp;
        size_--;
    }
    left->next = nullptr;
}
```

#### 代码

test代码：

```cpp
#include "../Lists/SLList.h"

int main() {
    int a[13] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6};
    SLList<int> s(a, 13);
    s.print();
    s.delRedundant();
    s.print();
    return 0;
}
```

输出：

![image-20260401202855078](C:\Users\22172\AppData\Roaming\Typora\typora-user-images\image-20260401202855078.png)

## 补充

关键代码作为`SLList`和`SeqList`的成员函数实现，详见`".\Lists\SLList.cpp"`和`".\Lists\SeqList.cpp"`

