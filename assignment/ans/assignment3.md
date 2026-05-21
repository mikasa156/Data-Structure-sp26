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
> 其中 $^$ 表示乘幂。

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
