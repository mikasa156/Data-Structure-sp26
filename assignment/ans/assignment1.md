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
