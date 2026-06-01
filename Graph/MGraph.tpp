#ifndef DATA_STRUCTURE_SP26_MGRAPH_TPP
#define DATA_STRUCTURE_SP26_MGRAPH_TPP

#include "MGraph.h"
#include "GraphDetail.h"
#include <iostream>
#include <queue>

namespace MST {
    constexpr int INF = 0x3f3f3f3f;
}
  // 约 1e9，且加法不易溢出

// ---------- DirectedMGraph ----------

template<typename T>
void DirectedMGraph<T>::countEdges() {
    edgeNum_ = 0;
    for (int i = 0; i < vexNum_; ++i) {
        for (int j = 0; j < vexNum_; ++j) {
            if (matrix_[i][j] != 0) {
                ++edgeNum_;
            }
        }
    }
}

template<typename T>
DirectedMGraph<T>::DirectedMGraph(int n, const std::vector<std::vector<T>>& matrix)
    : vexNum_(n), matrix_(matrix) {
    countEdges();
}

template<typename T>
DirectedMGraph<T>::DirectedMGraph(const std::string& csvFile)
    : vexNum_(0) {
    matrix_ = graph_detail::loadMatrixFromCsv<T>(csvFile, vexNum_);
    countEdges();
}

template<typename T>
void DirectedMGraph<T>::print() {
    std::cout << "DirectedMGraph (" << vexNum_ << " vertices, " << edgeNum_ << " edges):" << std::endl;
    for (int i = 0; i < vexNum_; ++i) {
        for (int j = 0; j < vexNum_; ++j) {
            std::cout << matrix_[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <typename T>
std::vector<int> DirectedMGraph<T>::bfs() {
    std::queue<int> queue;
    std::vector<bool> visited(vexNum_, false);
    std::vector<int> ans;

    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
        int v = queue.front();
        ans.push_back(v);
        queue.pop();

        for (int i = 0; i < vexNum_; i++) {
            if (!visited[i] && matrix_[v][i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    return ans;
}

template <typename T>
void DirectedMGraph<T>::dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans) {
    visited[v] = true;
    ans.push_back(v);
    for (int i = 0; i < vexNum_; i++) {
        if (visited[i] == false && matrix_[v][i] != 0) {
            dfsHelper(i, visited, ans);
        }
    }
}

template <typename T>
std::vector<int> DirectedMGraph<T>::dfs() {
    std::vector<int> ans;
    std::vector<bool> visited(vexNum_, false);
    dfsHelper(0, visited, ans);
    return ans;
}


// ---------- UndirectedMGraph ----------

template<typename T>
void UndirectedMGraph<T>::countEdges() {
    edgeNum_ = 0;
    for (int i = 0; i < vexNum_; ++i) {
        for (int j = i + 1; j < vexNum_; ++j) {
            if (matrix_[i][j] != 0) {
                ++edgeNum_;
            }
        }
    }
}

template<typename T>
UndirectedMGraph<T>::UndirectedMGraph(int n, const std::vector<std::vector<T>>& matrix)
    : vexNum_(n), matrix_(matrix) {
    countEdges();
}

template<typename T>
UndirectedMGraph<T>::UndirectedMGraph(const std::string& csvFile)
    : vexNum_(0) {
    matrix_ = graph_detail::loadMatrixFromCsv<T>(csvFile, vexNum_);
    countEdges();
}

template<typename T>
void UndirectedMGraph<T>::print() {
    std::cout << "UndirectedMGraph (" << vexNum_ << " vertices, " << edgeNum_ << " edges):" << std::endl;
    for (int i = 0; i < vexNum_; ++i) {
        for (int j = 0; j < vexNum_; ++j) {
            std::cout << matrix_[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <typename T>
std::vector<int> UndirectedMGraph<T>::bfs() {
    std::queue<int> queue;
    std::vector<bool> visited(vexNum_, false);
    std::vector<int> ans;

    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
        int v = queue.front();
        ans.push_back(v);
        queue.pop();

        for (int i = 0; i < vexNum_; i++) {
            if (!visited[i] && matrix_[v][i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    return ans;
}


template <typename T>
void UndirectedMGraph<T>::dfsHelper(int v, std::vector<bool>& visited, std::vector<int>& ans) {
    visited[v] = true;
    ans.push_back(v);
    for (int i = 0; i < vexNum_; i++) {
        if (!visited[i] && matrix_[v][i] != 0) {
            dfsHelper(i, visited, ans);
        }
    }
}

template <typename T>
std::vector<int> UndirectedMGraph<T>::dfs() {
    std::vector<int> ans;
    std::vector<bool> visited(vexNum_, false);
    dfsHelper(0, visited, ans);
    return ans;
}

template<typename T>
std::vector<std::pair<int, int> > UndirectedMGraph<T>::prim() {
    // 维护visited之外的点到visited的最小距离集合dist，不断从中取最小
    std::vector<bool> visited(vexNum_, false);
    std::vector<T> dist(vexNum_, MST::INF); // 点到当前集合的最小距离
    std::vector<int> parent(vexNum_, -1); // 记录前驱节点，用于复原出MST
    dist[0] = 0;

    for (int i = 0; i < vexNum_ - 1; i++) { // prim只需要n-1条边
        int v = -1; // 在这次迭代里面选出来加入的点，也就是到当前集合距离最小的点
        // 先找dist数组里的最小值，将这个点加入。并从这个点出发更新dist
        for (int j = 0; j < vexNum_; j++) { // 每次加入当前集合的点不一定顺序递增，必须从0开始保证不漏掉点
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (dist[v] == MST::INF) { // graph is not connected
            break;
        }
        visited[v] = true;

        // 更新点到当前集合的距离最小值
        for (int j = 0; j < vexNum_; j++) {
            if (!visited[j] && matrix_[v][j] != 0 && matrix_[v][j] < dist[j]) {
                dist[j] = matrix_[v][j];
                parent[j] = v; // key! 如果被更新了，那么一定是通过v点和当前集合链接的，前驱就一定是v
            }
        }
    }

    // 从parent中复原MST
    std::vector<std::pair<int, int>> ans;

    // note, 最小生成树只有n-1条边，一次遍历即可
    for (int i = 0; i < vexNum_; i++) {
        if (parent[i] != -1) {
            ans.emplace_back(parent[i], i);
        }
    }

    return ans;
}

#endif // DATA_STRUCTURE_SP26_MGRAPH_TPP
