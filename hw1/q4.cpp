#include <iostream>
#include <string>

bool check(const std::string& str);

int main() {
    std::string str;
    std::cin >> str;
    if (check(str)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return 0;
}

bool check(const std::string& str) {
    int left = 0; int right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false; 
        }
        left++; right--;
    }
    return true;
}
