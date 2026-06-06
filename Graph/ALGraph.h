#ifndef DATA_STRUCTURE_SP26_ALGRAPH_H
#define DATA_STRUCTURE_SP26_ALGRAPH_H

#include <vector>
#include <string>

template<typename T> class UndirectedMGraph;

template<typename T>
struct EdgeNode {
    int adjVex_;
    T weight_;
    EdgeNode* next_;
    EdgeNode(int adjVex, T weight, EdgeNode* next = nullptr)
        : adjVex_(adjVex), weight_(weight), next_(next) {}
};

template<typename T>
struct VexNode {
    int data_;
    EdgeNode<T>* firstEdge_;
    VexNode() : data_(0), firstEdge_(nullptr) {}
};

template<typename T>
class DirectedALGraph {
private:
    int vexNum_;
    int edgeNum_;
    std::vector<VexNode<T>> vertices_;
    void freeEdges();
    void buildFromMatrix(const std::vector<std::vector<T>>& matrix);
    void dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans);
    void hasPathDfsHelper(int v, std::vector<bool>& visited, const int& target, bool& hasFound);

public:
    DirectedALGraph(int n, const std::vector<std::vector<T>>& matrix);
    DirectedALGraph(const std::string& csvFile);
    ~DirectedALGraph();
    void print();
    std::vector<int> bfs();
    std::vector<int> dfs();
    bool hasPathBfs(int i, int j);
    bool hasPathDfs(int i, int j);
};

template<typename T>
class UndirectedALGraph {
private:
    int vexNum_;
    int edgeNum_;
    std::vector<VexNode<T>> vertices_;
    void freeEdges();
    void buildFromMatrix(const std::vector<std::vector<T>>& matrix);
    void dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans);
    void hasPathDfsHelper(int v, std::vector<bool>& visited, const int& target, bool& hasFound);

public:
    UndirectedALGraph(int n, const std::vector<std::vector<T>>& matrix);
    UndirectedALGraph(const std::string& csvFile);
    ~UndirectedALGraph();
    void print();
    std::vector<int> bfs();
    std::vector<int> dfs();
    std::vector<int> dfs_iter();
    UndirectedMGraph<T> toMatrix();
    bool hasPathBfs(int i, int j);
    bool hasPathDfs(int i, int j);
};

#include "ALGraph.tpp"

#endif // DATA_STRUCTURE_SP26_ALGRAPH_H
