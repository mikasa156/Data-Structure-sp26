# Assignment 2 答案

## 1. 选择题

**(1)** 线性表的顺序存储结构是一种（**A. 随机存取**）的存储结构，线性表的链式存储结构是一种（**B. 顺序存取**）的存储结构。

**(2)** 线性表采用链接存储时，其地址（**D. 连续与否均可以**）。

> 链式存储的地址可以不连续。

**(3)** 循环单链表的主要优点是（**B. 从表中任一结点出发都能扫描到整个链表**）。

**(4)** 链表不具有的特点是（**A. 可随机访问任一元素**）。

> 链表只能顺序访问。

**(5)** 若某线性表中最常用的操作是取第 $i$ 个元素和找第 $i$ 个元素的前趋，则采用（**A. 顺序表**）存储方法最节省时间。

**(6)** 若线性表中最常用的操作是在最后一个元素之后插入一个元素和删除第一个元素，则采用（**D. 带尾指针的单循环链表**）存储方法最节省时间。
> 尾指针使末尾插入为 $O(1)$，循环性使通过尾指针可直接访问第一个元素，删除为 $O(1)$。

**(7)** 若链表中最常用的操作是在最后一个结点之后插入一个结点和删除最后一个结点，则采用（**B. 循环双链表**）存储方法最节省运算时间。
> 通过头结点的 `prior` 可直接访问最后一个结点，插入和删除均为 $O(1)$。

**(8)** 在具有 $n$ 个结点的有序单链表中插入一个新结点并仍然保持有序的时间复杂度是（**B. $O(n)$**）。
> 需要遍历找到插入位置。

**(9)** 对于 $n$ 个元素组成的线性表，建立一个有序单链表的时间复杂度是（**C. $O(n^2)$**）。
> 逐个插入，每次最多遍历已有链表，总时间 $\sum_{i=1}^{n} i = O(n^2)$。

**(10)** 使用双链表存储线性表，其优点是可以（**B. 更方便数据的插入和删除**）。

**(11)** 在一个单链表中，已知 `q` 所指结点是 `p` 所指结点的直接前驱，若在 `q` 和 `p` 之间插入 `s` 所指结点，则执行（**B**）操作。
> `q->next = s; s->next = p;`

**(12)** 在循环双链表的 `p` 所指结点后插入 `s` 所指结点的操作是（**D**）。
> `s->prior = p; s->next = p->next; p->next->prior = s; p->next = s;`

**(13)** 用数组 `r` 存储静态链表，结点的 `next` 域指向后继，工作指针 `j` 指向链中某结点，则 `j` 后移的操作语句为（**A. `j = r[j].next`**）。

**(14)** 设线性表有 $n$ 个元素，以下操作中，（**A**）在顺序表上实现比在链表上实现的效率更高。
> 输出第 $i$ 个元素值：顺序表 $O(1)$，链表 $O(n)$。其余操作两者时间复杂度相同。

**(15)** 假设线性表只有 4 种基本操作：删除第一个元素；删除最后一个元素；在第一个元素前插入新元素；在最后一个元素之后插入新元素，则最好使用（**C. 只设尾指针的循环双链表**）。
> 尾指针可直接 $O(1)$ 访问最后一个元素；循环双链表通过尾指针的 `next` 可访问头结点，进而 $O(1)$ 完成首端操作；双链表的 `prior` 可 $O(1)$ 删除尾结点。

---

## 2. 解答下列问题

### (1) 顺序表和单链表的优缺点及适用场景

**答：**

| | 顺序表 | 单链表 |
|---|---|---|
| 优点 | 随机访问 $O(1)$，存储密度高 | 插入删除 $O(1)$（已知位置），动态分配 |
| 缺点 | 插入删除需移动元素，需预先分配空间 | 只能顺序访问，额外指针开销 |

① 采用**顺序表**——读取速度快，很少插入删除，适合随机存取。
② 采用**单链表**——各表长度动态变化，链表无需预先分配空间。

### (2) 相同逻辑结构不同存储方式效率不同

**答：** 以线性表为例：
- 顺序表查找第 $i$ 个元素 $O(1)$，单链表 $O(i)$
- 顺序表插入 / 删除 $O(n)$（需移动元素），单链表 $O(1)$（已知位置）

### (3) 希望随机存取又需要不同数据类型的存储结构

**答：** 设计**混合存储结构**——使用指针数组（顺序索引）+ 链表节点（存储实际数据）。索引表顺序存储实现随机存取，链表节点存储不同类型的数据。

### (4) 顺序存储方式所需存储空间

**答：** $D \times E$（顺序表需预先分配最大容量 $D$，每个单元占 $E$）

### (5) 单链表存储方式所需存储空间

**答：** $n \times (E + P)$（$n$ 个节点，每个节点含数据域 $E$ 和指针域 $P$）

---

## 3. 算法设计

### (1) 将元素 `x` 插入有序表 `L` 并保持有序

**思路：** 找到第一个大于等于 `x` 的位置，将该位置及之后的元素后移一位，插入 `x`。

```cpp
struct SeqList {
    int data[MAXSIZE];
    int length;
};

void insertSorted(SeqList &L, int x) {
    if (L.length >= MAXSIZE) return;
    int i = L.length - 1;
    while (i >= 0 && L.data[i] > x) {
        L.data[i + 1] = L.data[i];
        i--;
    }
    L.data[i + 1] = x;
    L.length++;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (2) 删除顺序表中所有值为 `x` 的元素，要求空间复杂度 $O(1)$

**思路：** 双指针法，用一个指针记录非 `x` 元素的存放位置。

```cpp
void deleteAllX(SeqList &L, int x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (3) 分别以顺序表和单链表实现逆置算法

**顺序表逆置（双指针交换）：**

```cpp
void reverseSeqList(SeqList &L) {
    int left = 0, right = L.length - 1;
    while (left < right) {
        int temp = L.data[left];
        L.data[left] = L.data[right];
        L.data[right] = temp;
        left++;
        right--;
    }
}
```

**单链表逆置（头插法）：**

```cpp
struct ListNode {
    int data;
    ListNode *next;
};

void reverseLinkedList(ListNode* &head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
```
**时间复杂度：** $O(n)$（两种方法）
**空间复杂度：** $O(1)$（两种方法）

### (4) 判断非空单链表是否递增有序

**思路：** 遍历链表，检查每个节点的 `data` 是否小于等于后继节点。

```cpp
bool isSortedAscending(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    ListNode* p = head;
    while (p->next != nullptr) {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (5) 按递增次序输出带头结点单链表的各节点数据元素，并释放结点空间

**思路：** 不允许使用数组辅助，每次遍历链表找出最小值结点，输出并删除，重复直至链表为空。

```cpp
void printAndFree(ListNode* head) {
    while (head->next != nullptr) {
        ListNode *pre = head, *p = head->next;
        ListNode *minPre = pre, *minP = p;
        while (p != nullptr) {
            if (p->data < minP->data) {
                minPre = pre;
                minP = p;
            }
            pre = p;
            p = p->next;
        }
        cout << minP->data << " ";
        minPre->next = minP->next;
        delete minP;
    }
    delete head;
}
```
**时间复杂度：** $O(n^2)$
**空间复杂度：** $O(1)$

---

## 4. 算法设计（续）

### (6) 删除非递减有序单链表中值相同的多余结点

**思路：** 遍历链表，比较相邻节点，若值相同则删除后继节点。

```cpp
void removeDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    ListNode* p = head->next;
    while (p != nullptr && p->next != nullptr) {
        if (p->data == p->next->data) {
            ListNode* q = p->next;
            p->next = q->next;
            delete q;
        } else {
            p = p->next;
        }
    }
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (7) 删除递增有序单链表中介于 `mink` 和 `maxk` 之间的所有元素

**思路：** 找到第一个 $\geq$ `mink` 的节点，然后删除所有 $<$ `maxk` 的节点。

```cpp
void deleteRange(ListNode* head, int mink, int maxk) {
    if (head == nullptr) return;
    ListNode *p = head, *q = p->next;
    while (q != nullptr && q->data <= mink) {
        p = q;
        q = q->next;
    }
    while (q != nullptr && q->data < maxk) {
        ListNode* temp = q;
        q = q->next;
        delete temp;
    }
    p->next = q;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (8) 判断序列 `B` 是否是序列 `A` 的子序列

**思路：** 双指针遍历两个链表，匹配元素。

```cpp
bool isSubsequence(ListNode* A, ListNode* B) {
    if (B == nullptr) return true;
    if (A == nullptr) return false;
    ListNode *p = A, *q = B;
    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            q = q->next;
        }
        p = p->next;
    }
    return q == nullptr;
}
```
**时间复杂度：** $O(m + n)$，$m$ 和 $n$ 分别为 `A`、`B` 的长度
**空间复杂度：** $O(1)$

### (9) 删除循环链表中结点 `s` 的前趋结点

**思路：** 在循环链表中找到 `s` 的前趋的前趋，然后删除 `s` 的前趋。

```cpp
void deletePredecessor(ListNode* s) {
    if (s == nullptr || s->next == s) return;
    ListNode *p = s;
    while (p->next->next != s) { // note
        p = p->next;
    }
    ListNode* toDelete = p->next;
    p->next = s;
    delete toDelete;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (10) 判断带头结点的双循环链表是否对称

**思路：** 双指针从两端向中间比较。

```cpp
struct DListNode {
    int data;
    DListNode *prior, *next;
};

bool isSymmetric(DListNode* head) {
    if (head == nullptr || head->next == head) return true;
    DListNode *left = head->next;
    DListNode *right = head->prior;
    while (left != right && left->prior != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prior;
    }
    return true;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (11) 在双链表中第 $i$ 个结点后面插入值为 `x` 的结点

**思路：** 找到第 $i$ 个结点，然后在其后插入新结点。

```cpp
void insertAfter(DListNode* head, int i, int x) {
    DListNode *p = head->next;
    int count = 1;
    while (p != head && count < i) {
        p = p->next;
        count++;
    }
    if (p == head) return;
    DListNode* s = new DListNode;
    s->data = x;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s; // 先改p->next的prev，再更新p->next.
    p->next = s;
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (12) 用单链表表示八进制数，实现 `Add` 函数

**思路：** 从低位（表尾）到高位（表头）逐位相加，处理进位。由于链表从高位到低位存储，需要先逆置。

```cpp
struct OctNode {
    int data;
    OctNode *next;
};

OctNode* reverseOct(OctNode* head) {
    OctNode *prev = nullptr, *curr = head;
    while (curr) {
        OctNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

OctNode* Add(OctNode* A, OctNode* B) {
    A = reverseOct(A);
    B = reverseOct(B);

    OctNode* result = nullptr;
    OctNode* tail = nullptr;
    int carry = 0;

    while (A || B || carry) {
        int sum = carry;
        if (A) { sum += A->data; A = A->next; }
        if (B) { sum += B->data; B = B->next; }

        OctNode* node = new OctNode;
        node->data = sum % 8;
        node->next = nullptr;
        carry = sum / 8;

        if (result == nullptr) {
            result = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return reverseOct(result);
}
```
**时间复杂度：** $O(\max(m, n))$，$m$、$n$ 分别为两个链表长度
**空间复杂度：** $O(1)$（不考虑结果链表）
