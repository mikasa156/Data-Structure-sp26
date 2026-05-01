#include "string"
#include <iostream>
using std::string;



bool isSubStr(string substr, string s) {
    if (substr.size() > s.size()) {
        return false;
    }
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

int main() {
    std::cout << (isComSub("sdu", "shandong university", "snake dog upset") ? "true" : "false") << std::endl;
    std::cout << (isComSub("", "sdu", "sdu_qingdao") ? "true" : "false") << std::endl;
    std::cout << (isComSub("hey", "hyw", "gugugaga") ? "true" : "false") << std::endl;
    std::cout << (isComSub("哈工大", "哈尔滨工业大学", "哈尔滨工程大学") ? "true" : "false") << std::endl;
}
