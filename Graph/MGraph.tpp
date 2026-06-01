#ifndef DATA_STRUCTURE_SP26_MGRAPH_TPP
#define DATA_STRUCTURE_SP26_MGRAPH_TPP

#include "MGraph.h"
#include "GraphDetail.h"
#include <iostream>
#include <queue>

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

#endif // DATA_STRUCTURE_SP26_MGRAPH_TPP
