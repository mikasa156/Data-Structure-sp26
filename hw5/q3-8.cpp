#include <iostream>
#include "../Graph/ALGraph.h"

int main() {
    std::vector<std::vector<int>> mat = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
    };
    DirectedALGraph<int> al_graph(5, mat);

    // BFS 路径测试
    std::cout << "(0, 0) Path: " << (al_graph.hasPathBfs(0, 0) ? "true" : "false") << "\n";
    std::cout << "(0, 2) Path: " << (al_graph.hasPathBfs(0, 2) ? "true" : "false") << "\n";
    std::cout << "(0, 3) Path: " << (al_graph.hasPathBfs(0, 3) ? "true" : "false") << "\n";

    // DFS 路径测试
    std::cout << "(0, 0) Path: " << (al_graph.hasPathDfs(0, 0) ? "true" : "false") << "\n";
    std::cout << "(0, 2) Path: " << (al_graph.hasPathDfs(0, 2) ? "true" : "false") << "\n";
    std::cout << "(0, 3) Path: " << (al_graph.hasPathDfs(0, 3) ? "true" : "false") << "\n";
    return 0;
}
