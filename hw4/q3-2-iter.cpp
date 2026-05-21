#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::string preOrder(const std::vector<char>& tree) {
    if (tree.size() <= 2 && tree[1] == '#') {
        return "";
    }// tree is empty

    int n = tree.size(); // n是tree数组的大小，比实际元素数多1.
    std::string ans = ""; // 结果字符串
    std::stack<int> stack;
    stack.push(1);

    while (!stack.empty()) {
        int k = stack.top();
        stack.pop();

        ans += tree[k];

        if (2 * k + 1 < n && tree[2 * k + 1] != '#') {
            stack.push(2 * k + 1);
        }
        if (k * 2 < n && tree[2 * k] != '#') {
            stack.push(2 * k);
        }
    }

    return ans;
}

int main() {
    std::vector<char> tree1 = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    std::vector<char> tree2 = {' ', 'A', 'B', 'C', 'D', 'E', '#', 'F'};
    std::vector<char> tree3 = {' ', '#'};

    std::string ans1 = preOrder(tree1);
    std::string ans2 = preOrder(tree2);
    std::string ans3 = preOrder(tree3);

    std::cout << ans1 << '\n';
    std::cout << ans2 << '\n';
    std::cout << ans3 << '\n';

    return 0;
}
