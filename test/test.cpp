#include "../Lists/SLList.h"

#include <vector>
bool isSub(vector<int> a, vector<int> b) {
    int left = 0;
    while (left < a.size() - b.size()) {
        for (int i = 0; i < b.size(); i++) {
            if (!a[left + i] == b[i]) {
                left++;
                break;
            }
            if (i == b.size() - 1 && a[left + i] == b[i]) {
                return true;
            }
        }
        return false;
    }
}
