# Assignment 1 答案

## 1. 选择题

**(1)** 顺序存储结构中数据元素之间的逻辑关系是由（**C. 存储位置**）表示的，链式存储结构中的数据元素之间的逻辑关系是由（**D. 指针**）表示的。

**(2)** 假设有如下遗产继承规则：丈夫和妻子可以相互继承遗产；子女可以继承父亲或母亲的遗产；子女间不能相互继承。则表示该遗产继承关系的数据结构应该是（**B. 图**）。
> 夫妻之间可相互继承形成环，不是树；用图表示最恰当。

**(3)** 计算机所处理的数据一般具有某种内在联系，这是指（**B. 元素和元素之间存在某种关系**）。

**(4)** 对于数据结构的描述，下列说法中不正确的是（**A**）。
> A 错误：相同的逻辑结构可以对应不同的存储结构（如线性表可用顺序表或链表实现）。

**(5)** 算法指的是（**A. 对特定问题求解步骤的一种描述，是指令的有限序列**）。

**(6)** 下面（**C. 高效性**）不是算法所必须具备的特性。
> 算法的五大特性：有穷性、确定性、可行性、输入、输出。高效性不是必须特性。

**(7)** 算法分析的目的是（**C. 分析算法的效率以求改进**），算法分析的两个主要方面是（**E. 空间性能和时间性能**）。

**(8)** 假设时间复杂度为 $O(n^2)$ 的算法在有 200 个元素的数组上运行需要 3.1ms，则在有 400 个元素的数组上运行需要（**C. 12.4**）ms。
> $(400/200)^2 \times 3.1 = 4 \times 3.1 = 12.4$

**(9)** 下列程序段加下画线的语句执行（**C. $n(n+1)$**）次。

执行次数 = $\sum_{i=1}^{n} 2i = 2 \cdot \frac{n(n+1)}{2} = n(n+1)$

---

## 2. 分析以下各程序段，并用大 $O$ 记号表示其执行时间

### (1)
```cpp
i = 1; k = 0;
while (i <= n) {
    k = k + 10 * i;
    i++;
}
```
**答：** $O(n)$。循环从 $i=1$ 到 $i=n$，每次 `i` 递增，共执行 $n$ 次。

### (2)
```cpp
i = 1; k = 0;
do {
    k = k + 10 * i;
    i++;
} while (i <= n);
```
**答：** $O(n)$。与 (1) 相同，只是 `do-while` 形式，循环执行 $n$ 次。

### (3)
```cpp
i = 1; j = 0;
while (i + j <= n)
    if (i > j) j++;
    else i++;
```
**答：** $O(n)$。每次循环 `i` 或 `j` 增加 1，$i+j$ 从 1 增长到 $n$，共执行约 $n$ 次。

### (4)
```cpp
y = 0;
while ((y + 1) * (y + 1) <= n)
    y = y + 1;
```
**答：** $O(\sqrt{n})$。循环条件等价于 $y+1 \leq \sqrt{n}$，$y$ 从 0 增长到约 $\sqrt{n}-1$，共执行约 $\sqrt{n}$ 次。

### (5)（第 26 页顶部）
```cpp
for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++)
        for (k = 1; k <= j; k++)
            x++;
```
**答：** $O(n^3)$。三重循环，执行次数为 $\sum_{i=1}^{n} \sum_{j=1}^{i} j = \sum_{i=1}^{n} \frac{i(i+1)}{2} \approx \frac{n^3}{6}$。

### (6)（第 26 页顶部）
```cpp
for (i = 1; i <= n; i++)
    for (j = 2 * i; j <= n; j++)
        y = i * j;
```
**答：** $O(n^2)$。外层 `i` 从 1 到 $n$，内层 `j` 从 $2i$ 到 $n$，当 $i > n/2$ 时内层不执行。
执行次数 $\approx \sum_{i=1}^{n/2} (n - 2i + 1) \approx \frac{n^2}{4}$。

---

## 3. 解答下列问题

### (1) 有向图邻接矩阵与邻接表

已知 $D=(V, R)$，其中 $V=\{1,2,3,4,5,6\}$，$R=\{\langle 1,2 \rangle,\langle 1,4 \rangle,\langle 2,3 \rangle,\langle 2,4 \rangle,\langle 2,3 \rangle,\langle 3,5 \rangle,\langle 3,6 \rangle,\langle 4,5 \rangle,\langle 6,1 \rangle\}$

**邻接矩阵（$6 \times 6$）：**

|   | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| 1 | 0 | 1 | 0 | 1 | 0 | 0 |
| 2 | 0 | 0 | 1 | 1 | 0 | 0 |
| 3 | 0 | 0 | 0 | 0 | 1 | 1 |
| 4 | 0 | 0 | 0 | 0 | 1 | 0 |
| 5 | 0 | 0 | 0 | 0 | 0 | 0 |
| 6 | 1 | 0 | 0 | 0 | 0 | 0 |

**邻接表：**
- 1 → 2 → 4 → ∧
- 2 → 3 → 4 → ∧
- 3 → 5 → 6 → ∧
- 4 → 5 → ∧
- 5 → ∧
- 6 → 1 → ∧

**结构类型：** 有向图

### (2) 抽象数据类型定义

```cpp
template <typename T>
class IntegerADT {
public:
    virtual T add(T a, T b) = 0;
    virtual T subtract(T a, T b) = 0;
    virtual T multiply(T a, T b) = 0;
    virtual T divide(T a, T b) = 0;
    virtual bool isEqual(T a, T b) = 0;
    virtual T input() = 0;
    virtual void output(T a) = 0;
};
```

### (3) 求多项式 $A(x)$ 的算法比较

**方法①：** $A(x) = a_0 x^n + a_1 x^{n-1} + \cdots + a_{n-1} x + a_n$

```cpp
double method1(double a[], int n, double x) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        double term = a[i];
        for (int j = 0; j < n - i; j++)
            term *= x;
        result += term;
    }
    return result;
}
```
**时间复杂度：** $O(n^2)$。每个项需要 $O(n-i)$ 次乘法，总计 $O(n^2)$。

**方法②：** $A(x) = (\cdots((a_0 x + a_1)x + a_2)x + \cdots + a_{n-1})x + a_n$（秦九韶算法 / Horner 法则）

```cpp
double method2(double a[], int n, double x) {
    double result = a[0];
    for (int i = 1; i <= n; i++)
        result = result * x + a[i];
    return result;
}
```
**时间复杂度：** $O(n)$。只需 $n$ 次乘法和 $n$ 次加法。

**比较：** 方法②（秦九韶算法）明显优于方法①，时间复杂度从 $O(n^2)$ 降到 $O(n)$。

---

## 4. 算法设计

### (1) 找出整型数组 `A[]` 中的最大值和次大值

**思路：** 一次遍历，维护最大值 `max1` 和次大值 `max2`。对每个元素，若大于 `max1` 则更新 `max1` 和 `max2`；否则若大于 `max2` 则更新 `max2`。

```cpp
void findMaxAndSecondMax(int A[], int n, int &max1, int &max2) {
    if (n < 2) return;
    if (A[0] > A[1]) { max1 = A[0]; max2 = A[1]; }
    else { max1 = A[1]; max2 = A[0]; }
    for (int i = 2; i < n; i++) {
        if (A[i] > max1) {
            max2 = max1;
            max1 = A[i];
        } else if (A[i] > max2 && A[i] < max1) {
            max2 = A[i];
        }
    }
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (2) 判断给定字符串是否是回文

**思路：** 双指针法，从两端向中间比较字符。

```cpp
bool isPalindrome(const char* str) {
    if (str == nullptr) return false;
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}
```
**时间复杂度：** $O(n)$，$n$ 为字符串长度
**空间复杂度：** $O(1)$

### (3) 将数组划分为奇数和偶数两部分

**思路：** 双指针法（类似快速排序的 partition），左指针找偶数，右指针找奇数，交换。

```cpp
void partitionOddEven(int A[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && A[left] % 2 != 0) left++;
        while (left < right && A[right] % 2 == 0) right--;
        if (left < right) {
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
        }
    }
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (4) 荷兰国旗问题

**思路：** 三指针法。用 `left` 指向 R 区域的下一个位置，`right` 指向 B 区域的前一个位置，`current` 遍历数组。遇到 R 放左边，遇到 B 放右边，遇到 W 跳过。

```cpp
void dutchFlag(char A[], int n) {
    int left = 0, current = 0, right = n - 1;
    while (current <= right) {
        if (A[current] == 'R') {
            swap(A[left], A[current]);
            left++;
            current++;
        } else if (A[current] == 'B') {
            swap(A[current], A[right]);
            right--;
        } else {
            current++;
        }
    }
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(1)$

### (5) 四人过桥问题

**思路：** 这是经典的贪心问题。四人过桥时间分别为 1, 2, 5, 10 分钟。

最优策略：
1. 甲 (1) 和乙 (2) 先过 → 2 分钟，甲带回手电筒 → 1 分钟
2. 丙 (5) 和丁 (10) 一起过 → 10 分钟，乙带回手电筒 → 2 分钟
3. 甲 (1) 和乙 (2) 再过 → 2 分钟

总时间 = 2 + 1 + 10 + 2 + 2 = **17 分钟**

```cpp
int minCrossingTime(int times[], int n) {
    sort(times, times + n);
    int total = 0;
    while (n >= 4) {
        int cost1 = times[0] + 2 * times[1] + times[n-1];
        int cost2 = 2 * times[0] + times[n-2] + times[n-1];
        total += min(cost1, cost2);
        n -= 2;
    }
    if (n == 3) total += times[0] + times[1] + times[2];
    else if (n == 2) total += times[1];
    else if (n == 1) total += times[0];
    return total;
}
```
**时间复杂度：** $O(n \log n)$（排序）
**空间复杂度：** $O(1)$
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
# Assignment 3 答案

## 1. 选择题

**(1)** 一个栈的入栈序列是 1,2,3,4,5，则栈的不可能的输出序列是（**C. 43512**）。
> 43512：push 1,2,3,4 → pop 4 → pop 3 → push 5 → pop 5 → 栈中剩 [1,2]，应出 2 再出 1，不能出 1 再出 2。

**(2)** 若一个栈的输入序列是 $1,2,3,\cdots,n$，输出序列的第一个元素是 $n$，则第 $i$ 个输出元素是（**D. $n-i+1$**）。
> 第一个出 $n$ 说明全部入栈了，出栈顺序就是 $n, n-1, \cdots, 1$。

**(3)** 若一个栈的输入序列是 $1,2,3,\cdots,n$，其输出序列是 $p_1, p_2, \cdots, p_n$，若 $p_1 = 3$，则 $p_2$ 的值（**C. 不可能是 1**）。
> $p_1=3$ 说明 1,2 已入栈且在 3 之下，出 3 后栈顶是 2，下一个只能出 2 或继续入栈。

**(4)** 设计一个判别表达式中左右括号是否配对的算法，采用（**C. 栈**）数据结构最佳。

**(5)** 当字符序列 1,2,3 依次通过栈，输出长度为 3 且可用作 C 语言标识符的序列有（**B. 5 个**）。
> 5 种出栈序列：123, 132, 213, 231, 321。

**(6)** 从栈顶指针为 `top` 的链栈中删除一个结点，用 `x` 保存被删除结点的值，则执行（**B**）。
> `x = top->data; top = top->next;`

**(7)** 在解决计算机主机与打印机之间速度不匹配问题时通常设置一个打印缓冲区，该缓冲区应该是一个（**B. 队列**）结构。

**(8)** 一个队列的入队顺序是 1,2,3 和 4，则队列的输出序列是（**B. 1234**）。

**(9)** 栈和队的主要区别在于（**D. 插入、删除运算的限定不一样**）。
> 栈是 LIFO（后进先出），队是 FIFO（先进先出）。

**(10)** 设顺序栈 $S_1$ 作为栈 S1 和 S2 的存储空间，对任何一个栈空时，为这个栈分配空间的最佳方案是（**A**）。
> S1 的栈底位置为 0，S2 的栈底位置为 $n-1$（两栈从两端向中间生长）。

**(11)** 设栈 $S$ 和队列 $Q$ 的初始状态为空，元素 $e_1,e_2,e_3,e_4,e_5,e_6$ 依次通过栈 $S$，一个元素出栈后即进入队列 $Q$，若 6 个元素出队的顺序是 $e_2,e_4,e_3,e_6,e_5,e_1$，则栈 $S$ 的容量至少应该是（**C. 3**）。
> 模拟过程：入 $e_1,e_2$ → 出 $e_2$ → 入 $e_3,e_4$ → 出 $e_4$ → 出 $e_3$ → 入 $e_5,e_6$ → 出 $e_6$ → 出 $e_5$ → 出 $e_1$。最大栈深为 3，故容量至少为 3。

**(12)** 表达式 $3 \times 2^{(4 + 2 \times 2 - 6 \times 3)} - 5$ 求值过程当中当扫描到 6 时，对象栈和算符栈为（**C**）。

---

## 2. 解答下列问题

### (1) 入栈序列 A、B、C、D、E，能否得到如下出栈序列？

**① C, E, A, B, D**
**答：** 不能。
- push A, push B, push C, pop C ✓
- push D, push E, pop E ✓
- 此时栈中从栈底到栈顶为 A, B, D
- 下一个出栈应为 D，但要求是 A，**不可能**

**② C, B, A, D, E**
**答：** 能。
- push A, push B, push C, pop C, pop B, pop A
- push D, pop D
- push E, pop E ✓

### (2) `push(1)`, `push(2)`, `pop`, `push(5)`, `push(7)`, `pop`, `push(6)` 后的栈顶和栈底

**操作过程：**
- `push(1)`: 栈 [1]
- `push(2)`: 栈 [1, 2]
- `pop`: 栈 [1]，弹出 2
- `push(5)`: 栈 [1, 5]
- `push(7)`: 栈 [1, 5, 7]
- `pop`: 栈 [1, 5]，弹出 7
- `push(6)`: 栈 [1, 5, 6]

**答：** 栈顶元素 = 6，栈底元素 = 1

### (3) `EnQueue(1)`, `EnQueue(2)`, `DeQueue`, `EnQueue(5)`, `EnQueue(7)`, `DeQueue`, `EnQueue(9)` 后的队头和队尾

**操作过程：**
- `EnQueue(1)`: [1]
- `EnQueue(2)`: [1, 2]
- `DeQueue`: [2]，出队 1
- `EnQueue(5)`: [2, 5]
- `EnQueue(7)`: [2, 5, 7]
- `DeQueue`: [5, 7]，出队 2
- `EnQueue(9)`: [5, 7, 9]

**答：** 队头元素 = 5，队尾元素 = 9

### (4) 判断入栈出栈序列的合法性

**① IOIIOIOO**
- push, pop, push, push, pop, push, pop, pop
- 操作：栈 [] → [1] → [] → [2] → [2,3] → [2] → [2,4] → [2] → []
- **合法** ✓

**② IOOIOIIO**
- push, pop, pop → 第二次 pop 时栈已空
- **不合法** ✗

**③ IIOIIOIO**
- push, push, pop, push, push, pop, push, pop
- **不合法**（push 4 次但 pop 4 次后还有元素未弹出）

**④ IIOIOIOO**
- push, push, pop, push, pop, push, pop, pop
- 栈 [] → [1] → [1,2] → [1] → [1,3] → [1] → [1,4] → [1] → []
- **合法** ✓

---

## 3. 算法设计

### (1) 用带头结点的循环链表表示队列，只设一个指针指向队尾结点，不设头指针

**思路：** 尾指针 `rear`，`rear->next` 即为头结点，头结点的 `next` 为队头元素。

```cpp
struct Node {
    int data;
    Node *next;
};

struct CircularQueue {
    Node *rear;
};

void initQueue(CircularQueue &Q) {
    Q.rear = new Node;
    Q.rear->next = Q.rear;
}

void enQueue(CircularQueue &Q, int x) {
    Node *s = new Node;
    s->data = x;
    s->next = Q.rear->next;
    Q.rear->next = s;
    Q.rear = s;
}

bool deQueue(CircularQueue &Q, int &x) {
    if (Q.rear->next == Q.rear) return false;
    Node *head = Q.rear->next;
    Node *p = head->next;
    x = p->data;
    head->next = p->next;
    if (p == Q.rear) Q.rear = head;
    delete p;
    return true;
}
```
**时间复杂度：** 入队 $O(1)$，出队 $O(1)$
**空间复杂度：** $O(1)$

### (2) 顺序栈 $S$ 有 $2n$ 个元素，重排为 $a_n, a_{n+2}, \cdots, a_{2n}, \cdots, a_{2n-1}, a_{2n-3}, \cdots, a_3, a_1$

**思路：** 观察重排规律——原序列的偶数位置元素（$a_2, a_4, \cdots, a_{2n}$）按原序排列在前半部分，奇数位置元素（$a_1, a_3, \cdots, a_{2n-1}$）按逆序排列在后半部分。

使用辅助队列：先将所有偶数位元素入队，再将奇数位元素压入辅助栈，然后出栈得到逆序。

```cpp
void rearrange(int S[], int n) {
    int total = 2 * n;
    std::queue<int> q;
    std::stack<int> st;

    for (int i = 0; i < total; i++) {
        if ((i + 1) % 2 == 0)
            q.push(S[i]);
        else
            st.push(S[i]);
    }

    int idx = 0;
    while (!q.empty()) {
        S[idx++] = q.front();
        q.pop();
    }
    while (!st.empty()) {
        S[idx++] = st.top();
        st.pop();
    }
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(n)$

### (3) 把十进制整数转换为二至九进制之间的任一进制输出

**思路：** 除基取余法，余数逆序输出（用栈）。

```cpp
void decimalToBase(int num, int base) {
    if (base < 2 || base > 9) return;
    if (num == 0) { cout << 0; return; }

    std::stack<int> s;
    bool negative = num < 0;
    if (negative) num = -num;

    while (num > 0) {
        s.push(num % base);
        num /= base;
    }

    if (negative) cout << '-';
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
```
**时间复杂度：** $O(\log_{\text{base}}(n))$
**空间复杂度：** $O(\log_{\text{base}}(n))$
# Assignment 4 答案

## 1. 选择题

**(1)** 设有两个字符串 `p` 和 `q`，求 `q` 在 `p` 中首次出现的位置的运算称作（**B. 模式匹配**）。

**(2)** 设模式 $T = \text{"abcaab"}$，则该模式的 `next` 值为（**A. $\{-1, 0, 0, 0, 1, 1\}$**）。
> `next[0]=-1`, `next[1]=0`, `next[2]=0`, `next[3]=0`, `next[4]=1`, `next[5]=1`。

**(3)** 二维数组 $A$ 的每个元素是由 6 个字符组成的字符串，行下标范围从 $0 \sim 8$，列下标的范围是从 $0 \sim 9$，则存放数组 $A$ 至少需要（**D. 540**）个字节。若 $A$ 按行优先方式存储，元素 $A[8][5]$ 的起始地址与当 $A$ 按列优先方式存储时的（**H. $A[4][9]$**）元素的起始地址一致。
> $9 \times 10 = 90$ 个元素 $\times$ 6 字节 = 540 字节。行优先 $A[8][5]$ 的偏移 = $8 \times 10 + 5 = 85$；列优先 $A[i][j]$ 的偏移 = $j \times 9 + i$，当 $j=9, i=4$ 时为 $9 \times 9 + 4 = 85$。

**(4)** 将数组称为随机存储结构是因为（**B. 对数组任一元素的存取时间是相等的**）。

**(5)** 下面的说法中，不正确的是（**A. 数组是一种非线性结构**）。
> 数组是线性结构。

**(6)** 对特殊矩阵采用压缩存储的主要目的是为了（**D. 减少不必要的存储空间**）。

**(7)** 下面（**C. 稀疏矩阵**）不属于特殊矩阵。
> 特殊矩阵包括对角矩阵、三角矩阵、对称矩阵等具有规律分布的矩阵；稀疏矩阵不属于特殊矩阵，它是另一类采用三元组表存储的矩阵。

**(8)** 下面的说法中，不正确的是（**B. 对称矩阵只需存放非零元素即可**）。
> 对称矩阵存放的是包括对角线在内的三角元素，不是只存非零元素（那是稀疏矩阵的做法）。

---

## 2. 解答下列问题

### (1) $n \times m$ 上三角阵以一维数组 `B` 存储，求 $a_{ij}$ 的存储位置

**答：** 上三角阵只存储 $i \leq j$ 的元素。以行为主序存储：
- 第 1 行有 $m$ 个元素（$j=1$ 到 $m$）
- 第 2 行有 $m-1$ 个元素（$j=2$ 到 $m$）
- ⋯
- 第 $i$ 行有 $m-i+1$ 个元素

$a_{ij}$ 之前有：
- 前 $i-1$ 行元素总数：$m + (m-1) + \cdots + (m-i+2) = \frac{(i-1)(2m-i+2)}{2}$
- 第 $i$ 行中 $a_{ij}$ 前有：$j - i$ 个元素

**存储位置：** $B\left[\frac{(i-1)(2m-i+2)}{2} + (j-i)\right]$

### (2) 三对角矩阵 $A_{n \times n}$，三条对角线元素存入 `B[3n-2]`

**答：** 三对角矩阵只有主对角线、上对角线、下对角线有非零元素，即 $|i-j| \leq 1$。

以行为主序存储三条对角线：
- 第 1 行：$a_{11}, a_{12}$（2 个元素）
- 第 2 行：$a_{21}, a_{22}, a_{23}$（3 个元素）
- 
- 第 $i$ 行：$a_{i,i-1}, a_{i,i}, a_{i,i+1}$（中间行为 3 个）
- 第 $n$ 行：$a_{n,n-1}, a_{n,n}$（2 个元素）

**用 $i,j$ 求 $k$：**
- 若 $j = i-1$（下对角线）：$k = 3(i-1) - 1$
- 若 $j = i$（主对角线）：$k = 3(i-1)$
- 若 $j = i+1$（上对角线）：$k = 3(i-1) + 1$

### (3) 稀疏矩阵三元组表

**三元组表（行, 列, 值）：**
- (0, 1, 6)
- (1, 0, 3)
- (2, 1, 5)
- (3, 7, 2)

### (4) 数组 $a[n][2n-2]$ 的三个顶点排序存放到 $B[n \times n]$ 中，求 $i,j$ 与 $k$ 的关系

根据图 4-29（矩阵中的三角形），将下三角部分存入一维数组：
- $k = \frac{i(i-1)}{2} + j$，其中 $i \geq j$
- 逆推：$i = \left\lfloor \frac{\sqrt{8k+1}-1}{2} \right\rfloor + 1$，$j = k - \frac{i(i-1)}{2}$

---

## 3. 算法设计

### (1) 模式匹配——严格匹配与松散匹配

**严格匹配（模式必须连续出现）：**

**思路：** 使用 BF（Brute Force）算法或 KMP 算法。

```cpp
int bfMatch(const char* text, const char* pattern) {
    int n = strlen(text), m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m) return i;
    }
    return -1;
}

void buildNext(const char* pattern, int next[]) {
    int m = strlen(pattern);
    next[0] = -1;
    int j = 0, k = -1;
    while (j < m - 1) {
        if (k == -1 || pattern[j] == pattern[k]) {
            j++; k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int kmpMatch(const char* text, const char* pattern) {
    int n = strlen(text), m = strlen(pattern);
    int *next = new int[m];
    buildNext(pattern, next);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++; j++;
        } else {
            j = next[j];
        }
    }
    delete[] next;
    return (j == m) ? i - m : -1;
}
```

**松散匹配（模式作为子序列，不要求连续）：**

**思路：** 判断 `pattern` 是否为 `text` 的子序列，或求最长公共子序列。

```cpp
int longestCommonSubsequence(const char* text, const char* pattern) {
    int n = strlen(text), m = strlen(pattern);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (text[i-1] == pattern[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

bool isSubsequence(const char* text, const char* pattern) {
    int i = 0, j = 0;
    while (text[i] && pattern[j]) {
        if (text[i] == pattern[j]) j++;
        i++;
    }
    return pattern[j] == '\0';
}
```
**时间复杂度：** BF 严格匹配 $O(n \times m)$，KMP 严格匹配 $O(n+m)$，子序列 $O(n+m)$

### (2) 矩阵鞍点——行最小且列最大的元素

**思路：** 先找每行的最小值及其列号，然后检查该元素是否为其所在列的最大值。

```cpp
void findSaddlePoint(int A[][MAXN], int m, int n) {
    for (int i = 0; i < m; i++) {
        int minCol = 0;
        for (int j = 1; j < n; j++)
            if (A[i][j] < A[i][minCol])
                minCol = j;

        bool isSaddle = true;
        for (int k = 0; k < m; k++)
            if (A[k][minCol] > A[i][minCol]) {
                isSaddle = false;
                break;
            }

        if (isSaddle)
            cout << "Saddle point: A[" << i << "][" << minCol << "] = " << A[i][minCol] << endl;
    }
}
```
**时间复杂度：** $O(m \times n)$
**空间复杂度：** $O(1)$

### (3) 判定元素 `x` 是否在特殊矩阵 $A$ 中

**题目条件：** 矩阵 $A$ 满足 $A[i][j] \leq A[i][j+1]$（每行递增）且 $A[i][j] \leq A[i+1][j]$（每列递增）

**思路：** 从右上角（或左下角）开始搜索。若当前元素大于 `x`，向左移动；若小于 `x`，向下移动。

```cpp
bool searchMatrix(int A[][MAXN], int m, int n, int x) {
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (A[i][j] == x)
            return true;
        else if (A[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
}
```
**时间复杂度：** $O(m + n)$
**空间复杂度：** $O(1)$
# Assignment 5 答案

## 1. 选择题

**(1)** 一个高度为 $h$ 的满二叉树共 $n$ 个结点，其中有 $m$ 个叶子结点，则有（**D. $n = 2m - 1$**）成立。
> 满二叉树：$n = 2^h - 1$，$m = 2^{h-1}$，代入得 $n = 2m - 1$。

**(2)** 设二叉树有 $n$ 个结点，则其深度为（**D. 不能确定**）。
> 不同形态的二叉树深度不同，最少 $\lfloor \log_2 n \rfloor + 1$，最多 $n$。

**(3)** 二叉树的前序序列和中序序列正好相反，则该二叉树一定是（**C. 任一结点无左孩子**）的二叉树。
> 前序：根左右，中序：左根右。相反说明没有左子树。

**(4)** 线索二叉树中某结点 `R` 没有左孩子的充要条件是（**B. `R.ltag = 0`** 或 **C/D**，视教材定义而定）。
> 在线索二叉树中，`lchild` 指针要么指向左孩子，要么作为线索指向前驱，因此不能仅凭 `lchild == NULL` 判断。通常约定 `ltag = 0` 表示有左孩子，`ltag = 1` 表示无左孩子（线索）；若教材定义相反，则选 `ltag = 0`。原答案 A 不准确。

**(5)** 深度为 $k$ 的完全二叉树至少有（**$2^{k-1}$**）个结点，至多有（**$2^k - 1$**）个结点。

**(6)** 任何一棵二叉树的叶子结点在前序、中序、后序遍历序列中的相对次序（**A. 肯定不发生改变**）。

**(7)** 设森林中有 4 棵树，树中结点的个数依次为 $n_1, n_2, n_3, n_4$，则把森林转换成二叉树后，其根结点的右子树上有（**D. $n_2 + n_3 + n_4$**）个结点。
> 根结点的右子树对应森林中除第一棵树外的所有树。

**(8)** 讨论树、森林和二叉树的关系，目的是为了（**B. 借助二叉树上的运算方法去实现对树的一些运算**）。

**(9)** 为 5 个使用频率不等的字符设计哈夫曼编码，不可能的方案是（**D. $\{00, 100, 101, 110, 111\}$**）。

**(10)** 为 5 个使用频率不等的字符设计哈夫曼编码，不可能的方案是（**C. $\{000, 001, 01, 10, 11\}$**）。
> 用 Kraft 不等式验证：
> - A: $3 \times 2^{-3} + 2 \times 2^{-2} = \frac{3}{8} + \frac{1}{2} = \frac{7}{8} < 1$ ✓
> - B: $2 \times 2^{-3} + 3 \times 2^{-2} = \frac{2}{8} + \frac{3}{4} = 1$ ✓
> - C: $2 \times 2^{-3} + 3 \times 2^{-2} = \frac{2}{8} + \frac{3}{4} = 1$ ✓
> - D: $2^{-2} + 4 \times 2^{-3} = \frac{1}{4} + \frac{4}{8} = \frac{3}{4} < 1$ ✓

---

## 2. 解答下列问题

### (1) 双亲孩子表示法的存储示意图

**思路：** 在数组的每个表头结点中增加一个域存储该结点的双亲结点在数组中的下标。

```cpp
struct PTNode {
    char data;
    int parent;
    int firstChild;
    int nextSibling;
};

struct PTree {
    PTNode nodes[MAXSIZE];
    int root;
    int n;
};
```

### (2) 证明：任意一棵二叉树中分支结点数 $B = n_0 - 1$

**证明：**
- 设 $n_0$ 为叶子结点数（度为 0），$n_1$ 为度为 1 的结点数，$n_2$ 为度为 2 的结点数（即分支结点 $B$）
- 总结点数：$n = n_0 + n_1 + n_2$
- 总边数（分支数）：$n - 1$（每结点除根外有 1 条入边）
- 总边数也等于各结点出度之和：$n_1 + 2n_2$
- 所以：$n_1 + 2n_2 = n - 1 = n_0 + n_1 + n_2 - 1$
- 化简：$n_2 = n_0 - 1$
- 即 **$B = n_2 = n_0 - 1$**

> 注：题目中写的 $B = 2(n_0 - 1)$ 有误，正确结论应为 $B = n_0 - 1$。

### (3) 证明：已知前序和中序序列可唯一确定二叉树

**证明：**
- 前序序列的第一个元素为根结点
- 在中序序列中找到根结点，中序序列中根左边为左子树，右边为右子树
- 根据左右子树的结点个数，从前序序列中划分出左右子树的前序序列
- 递归处理左右子树，直到子树为空
- 由于每一步划分都是唯一的，故二叉树唯一确定

### (4) 度为 $m$ 的树中共有多少个叶子结点

**已知：** $n_1$ 个度为 1 的结点，$n_2$ 个度为 2 的结点，⋯，$n_m$ 个度为 $m$ 的结点

**解：**
- 总结点数：$n = n_0 + n_1 + n_2 + \cdots + n_m$
- 总边数：$n - 1 = 1 \cdot n_1 + 2 \cdot n_2 + \cdots + m \cdot n_m$
- $n_0 + n_1 + n_2 + \cdots + n_m - 1 = n_1 + 2n_2 + \cdots + mn_m$
- **$n_0 = 1 + n_2 + 2n_3 + 3n_4 + \cdots + (m-1)n_m = 1 + \sum_{k=2}^{m} (k-1) \cdot n_k$**

### (5) 根据中序 CBEDAFIGH 和后序 CEDBIFHGA 构造二叉树

**思路：** 后序的最后一个元素为根 A，在中序中找到 A，左边 CBED 为左子树，右边 FIGH 为右子树。

**构造结果：**
```
        A
       / \
      B   G
     / \  / \
    C   D F   H
       /   \
      E     I
```
> 后序最后一个元素 `A` 为根；中序中 `A` 左侧 `CBED` 为左子树，右侧 `FIGH` 为右子树。
> - 左子树后序 `CEDB` → 根为 `B`；中序 `CBED` 中 `B` 左侧为 `C`，右侧为 `ED`。
>   - `ED` 的后序为 `ED` → 根为 `D`，中序 `ED` 中 `E` 在左侧，故 `D` 的左孩子为 `E`。
> - 右子树后序 `IFHG` → 根为 `G`；中序 `FIGH` 中 `G` 左侧为 `FI`，右侧为 `H`。
>   - `FI` 的后序为 `IF` → 根为 `F`，中序 `FI` 中 `I` 在右侧，故 `F` 的右孩子为 `I`。
>   - `H` 为 `G` 的右孩子。

### (6) 7 个字符的哈夫曼编码

**频率：** a:0.31, b:0.16, c:0.10, d:0.08, e:0.11, f:0.20, g:0.04

**构建哈夫曼树（每次合并权值最小的两个结点）：**
1. g(0.04), d(0.08) → 0.12
2. c(0.10), e(0.11) → 0.21
3. 0.12(gd), b(0.16) → 0.28
4. **f(0.20), 0.21(ce)** → **0.41**  （此处原答案误将 0.21 与 0.28 合并，应选最小的两个 0.20 与 0.21）
5. **a(0.31), 0.28(gdb)** → **0.59**
6. 0.41, 0.59 → 1.0

**哈夫曼编码（一种可能的赋值，不唯一）：**
- a: 10
- b: 011
- c: 000
- d: 0101
- e: 001
- f: 11
- g: 0100
> 哈夫曼编码要求每次选取权值最小的两棵子树合并。虽然不同的合并顺序可能得到相同的最优带权路径长度，但第 4 步必须选当前最小的两个 0.20 与 0.21。

### (7) 三进制编码的最短总长度

**频率：** A:8, B:5, C:3, D:2, E:7, F:23, G:9, H:11, I:2, J:35

**三进制哈夫曼编码：** 每次合并 3 个最小频率的结点。

总频率 = $8+5+3+2+7+23+9+11+2+35 = 105$

最短总长度 = $\sum (\text{频率} \times \text{编码长度})$

通过构建三进制哈夫曼树计算：
- J(35): 长度 1
- F(23): 长度 1
- H(11): 长度 2
- A(8): 长度 2
- G(9): 长度 2
- E(7): 长度 2
- B(5): 长度 3
- C(3): 长度 3
- D(2): 长度 3
- I(2): 长度 3

**最短总长度 ≈ $35 \times 1 + 23 \times 1 + 11 \times 2 + 8 \times 2 + 9 \times 2 + 7 \times 2 + 5 \times 3 + 3 \times 3 + 2 \times 3 + 2 \times 3 = 152$**

---

## 3. 算法设计

### (1) 计算二叉树的结点个数

```cpp
struct BiTNode {
    int data;
    BiTNode *lchild, *rchild;
};

int countNodes(BiTNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$，$h$ 为树高（递归栈）

### (2) 按前序次序打印二叉树中的叶子结点

```cpp
void printLeavesPreorder(BiTNode* root) {
    if (root == nullptr) return;
    if (root->lchild == nullptr && root->rchild == nullptr)
        cout << root->data << " ";
    printLeavesPreorder(root->lchild);
    printLeavesPreorder(root->rchild);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$

### (3) 求二叉树的深度

```cpp
int getDepth(BiTNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = getDepth(root->lchild);
    int rightDepth = getDepth(root->rchild);
    return 1 + max(leftDepth, rightDepth);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$

### (4) 顺序存储二叉树的前序遍历

**思路：** 对于顺序存储（数组 `bt[1..n]`），结点 `i` 的左孩子为 $2i$，右孩子为 $2i+1$。

```cpp
void preorderSeq(int bt[], int n, int i) {
    if (i > n || bt[i] == 0) return;
    cout << bt[i] << " ";
    preorderSeq(bt, n, 2 * i);
    preorderSeq(bt, n, 2 * i + 1);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$

### (5) 深度为 $h$ 的二叉树（数组 `BT[1..2^h-1]`），求叶子结点个数

**思路：** 叶子结点是没有孩子的结点，即 $2i > 2^h - 1$ 或 `bt[2i] == 0` 且 `bt[2i+1] == 0`。

```cpp
int countLeaves(int BT[], int h) {
    int count = 0;
    int total = (1 << h) - 1;
    for (int i = 1; i <= total; i++) {
        if (BT[i] == 0) continue;
        int left = 2 * i, right = 2 * i + 1;
        if ((left > total || BT[left] == 0) &&
            (right > total || BT[right] == 0))
            count++;
    }
    return count;
}
```
**时间复杂度：** $O(2^h)$
**空间复杂度：** $O(1)$

### (6) 顺序存储二叉树中编号为 $i$ 和 $j$ 的两个结点的最近公共祖先

**思路：** 对于完全二叉树的顺序存储，结点 $i$ 的双亲为 $\lfloor i/2 \rfloor$。不断将较大编号除以 2，直到两个编号相等。

```cpp
int findLCA(int i, int j) {
    while (i != j) {
        if (i > j) i /= 2;
        else j /= 2;
    }
    return i;
}
```
**时间复杂度：** $O(\log n)$
**空间复杂度：** $O(1)$

### (7) 二叉链表中求结点 `x` 的双亲

```cpp
BiTNode* findParent(BiTNode* root, int x) {
    if (root == nullptr || root->data == x) return nullptr;
    if ((root->lchild && root->lchild->data == x) ||
        (root->rchild && root->rchild->data == x))
        return root;
    BiTNode* p = findParent(root->lchild, x);
    if (p != nullptr) return p;
    return findParent(root->rchild, x);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$

### (8) 二叉树中删除以值 `x` 为根结点的子树

```cpp
void deleteSubtree(BiTNode* root) {
    if (root == nullptr) return;
    deleteSubtree(root->lchild);
    deleteSubtree(root->rchild);
    delete root;
}

bool deleteSubtreeByValue(BiTNode* &root, int x) {
    if (root == nullptr) return false;
    if (root->data == x) {
        deleteSubtree(root);
        root = nullptr;
        return true;
    }
    if (deleteSubtreeByValue(root->lchild, x)) return true;
    return deleteSubtreeByValue(root->rchild, x);
}
```
**时间复杂度：** $O(k)$，$k$ 为以 `x` 为根的子树结点数
**空间复杂度：** $O(h)$

### (9) 交换二叉树中所有结点的左右子树

```cpp
void swapChildren(BiTNode* root) {
    if (root == nullptr) return;
    swap(root->lchild, root->rchild);
    swapChildren(root->lchild);
    swapChildren(root->rchild);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$

### (10) 孩子兄弟表示法求树中结点 `x` 的第 $i$ 个孩子

**孩子兄弟表示法：** 每个结点有 `firstChild`（第一个孩子）和 `nextSibling`（下一个兄弟）指针。

```cpp
struct CSNode {
    int data;
    CSNode *firstChild;
    CSNode *nextSibling;
};

CSNode* getIthChild(CSNode* root, int x, int i) {
    if (root == nullptr) return nullptr;
    if (root->data == x) {
        CSNode* child = root->firstChild;
        int count = 1;
        while (child != nullptr && count < i) {
            child = child->nextSibling;
            count++;
        }
        return child;
    }
    CSNode* result = getIthChild(root->firstChild, x, i);
    if (result != nullptr) return result;
    return getIthChild(root->nextSibling, x, i);
}
```
**时间复杂度：** $O(n)$
**空间复杂度：** $O(h)$
