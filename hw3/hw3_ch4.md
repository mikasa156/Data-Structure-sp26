# Chapter 4

*信计 杨其霄 202300091132*

## q2

![image-20260429200420223](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260429200420223.png)

![image-20260429200441520](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260429200441520.png)

**三元组顺序表表示**：

| index |  i   |  j   |  val  |
| :---: | :--: | :--: | :---: |
|   0   |  1   |  2   | **6** |
|   1   |  1   |  5   | **8** |
|   2   |  2   |  1   | **3** |
|   3   |  3   |  2   | **5** |
|   4   |  4   |  5   | **2** |
|       | 空闲 | 空闲 | 空闲  |

| 4（矩阵的行数） |
| :-------------: |
| 6（矩阵的列数） |
| 5（非零元个数） |

**十字链表存储表示**：

![](C:\CS\data-structure-sp26\hw3\微信图片_20260430194412_21_2.jpg)

## q3

### (1)

![image-20260429202617630](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260429202617630.png)

#### 基本思路

给定子串`substr`， 和主串`s1, s2`。

分别判断substr是否是s1，s2的子序列，如果均为真那么返回true。而由子序列的性质，只需逐项判断子串元素是否在主串当中即可。

- 如果substr长度为0，返回true。空串应该是所有字符串的子序列。

- 如果substr长度大于s1或s2，返回false
- 初始化下标`index = 0`，遍历s1元素item：
  - 如果`index == substr.size()`，说明substr的元素都在主串中，返回true
  - 如果`substr[index] == item`，index++
- 返回false

#### 伪代码

```cpp
bool isSubStr(string substr, string s) {
    if (substr.size() == 0) return true; // empty string
    if (substr.size() > s.size()) return false; // sub-string is 	longer than s
    int index = 0;
    for (const auto& item : s) {
        if (index == substr.size()) {
            return true;
        }
        if (item == substr[index]) {
            index++;
        }
    }
    return false;
}

bool isComSub(string substr, string s0, string s2) {
    return isSubStr(substr, s0) && isSubStr(substr, s2);
}
```

#### 代码

test代码

```cpp
#include "string"
#include <iostream>
using std::string;

bool isComSub(string substr, string s);

int main() {
    std::cout << (isComSub("sdu", "shandong university", "snake dog upset") ? "true" : "false") << std::endl;
    std::cout << (isComSub("", "sdu", "sdu_qingdao") ? "true" : "false") << std::endl;
    std::cout << (isComSub("hey", "hyw", "gugugaga") ? "true" : "false") << std::endl;
    std::cout << (isComSub("哈工大", "哈尔滨工业大学", "哈尔滨工程大学") ? "true" : "false") << std::endl;
}

```

**输出**：

![image-20260430093359320](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260430093359320.png)

### (2)

![image-20260430093626328](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260430093626328.png)

#### 基本思路

1. 给定矩阵`mat`，先遍历每一行，找到最小元素，加入到最小值向量`mins`中。再遍历每一列，找到最大元素，加入到最大值向量`maxs`中。

1. 访问矩阵每一个元素`mat[i][j]`，如果该元素既是当前行最小，也是当前列最大，即`mat[i][j] == mins[i] && mat[i][j] == maxs[j]`，那么其坐标就是鞍点，输出即可。注意数组坐标转为自然下标要加1即可。


**复杂度分析**：

1. 在预处理找最值阶段，对每一列找最大是$O(n)$，对每一行找最小是$O(m)$，总共就是：

$m*O(n) + n*O(m) = O(mn)$

2. 遍历每一个元素，总共有mn个，因此是$O(mn)$
3. 总复杂度：$O(mn) + O(mn) = O(mn)$

#### 伪代码

```cpp
/** 找每一行的最小值 */
auto rowMin(const std::vector<std::vector<double>>& mat) {
    std::vector<double> mins; // 最小值向量
    for (const auto& vec : mat) {
        double min = vec[0];
        for (const auto& x : vec) {
            if (x < min) {
                min = x;
            }
        }
        mins.push_back(min);
    }
    return mins;
}

/** 找每一列的最大值 */
auto columnMax(const std::vector<std::vector<double>>& mat) {
    std::vector<double> maxs; // 最大值向量
    for (int j = 0; j < mat[0].size(); j++) {
        double max = mat[0][j];
        for (const auto& vec : mat) {
            if (vec[j] > max) {
                max = vec[j];
            }
        }
        maxs.push_back(max);
    }
    return maxs;
}

/** 遍历矩阵找鞍点 */
auto findSaddle(const std::vector<std::vector<double>>& mat) {

    std::vector<std::pair<int, int>> saddle_points; // 结果矩阵

    auto mins = rowMin(mat);
    auto maxs = columnMax(mat);

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == mins[i] && mat[i][j] == maxs[j]) {
                std::pair<int, int> p {i + 1, j + 1};
                saddle_points.push_back(p);
            }
        }
    }
    return saddle_points;
}
```

#### 代码

```cpp
#include <iostream>
#include <vector>
#include <utility>

auto rowMin(const std::vector<std::vector<double>>& mat);
auto columnMax(const std::vector<std::vector<double>>& mat);
auto findSaddle(const std::vector<std::vector<double>>& mat);

/** 打印结果 */
void printPoints(std::vector<std::pair<int, int>> points) {
    for (const auto& point : points) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<double>> mat {
        {1, 1}, 
        {1, 1}
    };

    std::vector<std::vector<double>> mat2 {
        {1, 2, 2, 2, 2},
        {0, 2, 0, 0, 0},
        {1, 2, 3, 4, 5},
        {1, 1, 2, 2, 2}
    };

    printPoints(findSaddle(mat));
    printPoints(findSaddle(mat2));

    return 0;
}

```

**输出**：

![image-20260430170026293](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260430170026293.png)



