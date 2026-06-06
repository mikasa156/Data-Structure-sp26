#include "../Graph/ALGraph.h"

int main() {
    std::vector<std::vector<int>> mat = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 1, 1, 0},
    };
    UndirectedALGraph<int> alg(7, mat);
    std::vector<int> vec = alg.dfs_iter();
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    return 0;
}
