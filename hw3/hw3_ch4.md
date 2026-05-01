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
    if (substr.size() > s.size()) return false; // sub-	     string is longer than s
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

1. 设二维数组的每一个元素是一个行向量。先遍历第j列元素，找出第j列最大的元素所在的行，设取出的最大值所在行集合为Sj。

2. 对Sj中每个行i，验证aij是否是i行最小元素，是则加入到鞍点集合。否则j++，转步骤1，继续操作，直到j==m。

**复杂度分析**：

1. 对某一列，遍历寻找最大元素是$O(n)$，再取出最大值行所在行集合也是$O(n)$的，总的是$O(n)+O(n)=O(n)$。

2. 对于Sj，从中取一行指标i，判断(i, j)是否是行最小元素的复杂度是$O(m)$。最坏情况下，一列中每个元素都相等时每个元素都是最大值元素，要对n个行指标分析。因此最坏复杂度就是$O(nm)$。
3. 总共有m列，因此总共的复杂度就是：

$$
O(m(n+nm))=O(nm + nm^2) = O(nm^2)
$$

#### 伪代码

```cpp
#include <vector>
#include <utility>

/** 检查某一值是否是某行最小值 */
bool isMin(double val, std::vector<double>& vec) {
    for (const auto& item : vec) {
        if (val > item) return false;
    }
    return true;
}

auto findSaddle(std::vector<std::vector<double>> mat) {
    int n = mat.size(); // 矩阵行数
    int m = mat[0].size(); // 矩阵列数
	
    std::vector<std::pair<int, int>> saddle_points; // 输	出矩阵，存储鞍点坐标

    for (int j = 0; j < m; j++) {
        double j_max = mat[0][j]; // 第j列的最大值 
        
        std::vector<int> Sj; // 候选集，其中元素是第j列所有取		   到最大值的行 
 
        /**
         * 对第j列，遍历所有行，如果矩阵在ij位置的值大于j_max，
         * 更新j_max，将i加入Sj；
         * 如果ij位置的值等于j_max，不更新，只将i加入Sj
         */
        for (int i = 0; i < n; i++) { 
            if (mat[i][j] > j_max) {
                j_max = mat[i][j];
                Sj.clear();
                Sj.push_back(i);
            }
            else if (mat[i][j] == j_max) { 
                Sj.push_back(i);
            }
        }
        
        /**
        * 取出Sj中所有的行i，判断矩阵在ij处的值是否
        * 是第i行的最小值。如果是，那么将坐标(i, j)
        * 加入输出数组'saddle_points'
        */
        for (const auto& r : Sj) {
            if (isMin(mat[r][j], mat[r])) {
                // cpp下标转自然下标要加一
                std::pair<int, int> p{r+1, j+1};
                saddle_points.push_back(p);
            }
        }
    }
    return saddle_points;
}

```

#### 代码

```cpp
#include <vector>
#include <utility>
#include <iostream>

bool isMin(double val, std::vector<double>& vec);
auto findSaddle(std::vector<std::vector<double>> mat);

void printPoints(std::vector<std::pair<int, int>> points) {
    for (const auto& item : points) {
        std::cout << "(" << item.first << ", " << item.second << ") ";
    }
}

int main(){
    std::vector<std::vector<double>> mat {
        {0, 0, 0, 0, 0},
        {4, 4, 5, 6, 7},
        {1, 3, 3, 3, 4},
        {0, 0, 0, 0, 0}
    };

    std::vector<std::vector<double>> mat2 {
        {1, 2, 3, 4, 5},
        {1, 1, 2, 2, 2},
    };

    printPoints(findSaddle(mat));
    std::cout << std::endl;
    printPoints(findSaddle(mat2));
    return 0;
}

```

**输出**：

![image-20260430170026293](C:\Users\yurino\AppData\Roaming\Typora\typora-user-images\image-20260430170026293.png)



