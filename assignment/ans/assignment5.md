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
