#ifndef DATA_STRUCTURE_SP26_MGRAPH_H
#define DATA_STRUCTURE_SP26_MGRAPH_H

#include <vector>
#include <string>

template<typename T>
class DirectedMGraph {
private:
    int vexNum_;
    int edgeNum_;
    std::vector<std::vector<T>> matrix_;
    void countEdges();
    void dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans);

public:
    DirectedMGraph(int n, const std::vector<std::vector<T>>& matrix);
    DirectedMGraph(const std::string& csvFile);
    void print();
    std::vector<int> bfs();
    std::vector<int> dfs();
};

template<typename T>
class UndirectedMGraph {
private:
    int vexNum_;
    int edgeNum_;
    std::vector<std::vector<T>> matrix_;
    void countEdges();
    void dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans);

public:
    UndirectedMGraph(int n, const std::vector<std::vector<T>>& matrix);
    UndirectedMGraph(const std::string& csvFile);
    void print();
    std::vector<int> bfs();
    std::vector<int> dfs(); // traverse every node, rather than edge
    std::vector<std::pair<int, int>> prim();
};

#include "MGraph.tpp"

#endif // DATA_STRUCTURE_SP26_MGRAPH_H
