#include <stack>
#include <string>
#include <iostream>

std::string dec_2_base(int num, int base) {
    std::stack<int> p_num;
    std::string ans;

    std::cout << num << "(10) = ";

    if (num == 0) {
        // edge situation
        std::cout << "0(" << base << ")" << std::endl;
        return "0";
    }
    if (num < 0) {
        ans = "-";
        num = -num;
    }
    while (num != 0) {
        int quotient = num / base;
        int remainder = num % base;
        p_num.push(remainder);
        num = quotient;
    }
    while (!p_num.empty()) {
        int top = p_num.top();
        p_num.pop();
        ans += std::to_string(top);
    }
    std::cout << ans << "(" << base << ")" << std::endl;
    return ans;
}

int main() {
    dec_2_base(5, 2);
    dec_2_base(10, 10);
    dec_2_base(100,9);
    dec_2_base(89, 7);
    dec_2_base(-58, 8);
    dec_2_base(0, 9);
    return 0;
}
