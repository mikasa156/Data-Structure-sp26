#include <iostream>
#include <vector>

/**
 * @param tree 树的顺序存储
 * @param n 数组大小
 * @param k 下标
 * @param ans 结果字符串
 */
void preOrder(const std::vector<char>& tree, auto& n, int k, std::string& ans) {
    if (n <= 2 && tree[1] == '#') {
        return;
    }
    if (k >= n || tree[k] == '#') {
        return;
    }
    ans += tree[k];
    preOrder(tree, n, 2 * k, ans);
    preOrder(tree, n,2 * k + 1, ans);
}


int main() {
    std::vector<char> tree1 = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    std::vector<char> tree2 = {' ', 'A', 'B', 'C', 'D', 'E', '#', 'F'};
    std::vector<char> tree3 = {' ', '#'};
    int n1 = tree1.size(); int n2 = tree2.size(); int n3 = tree3.size();

    std::string pre1, pre2, pre3;
    preOrder(tree1, n1, 1, pre1);
    preOrder(tree2, n2, 1, pre2);
    preOrder(tree3, n3, 1, pre3);

    std::cout << pre1 << '\n';
    std::cout << pre2 << '\n';
    std::cout << pre3 << '\n';

    return 0;
}
