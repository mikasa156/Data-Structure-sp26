#ifndef DATA_STRUCTURE_SP26_ALGRAPH_TPP
#define DATA_STRUCTURE_SP26_ALGRAPH_TPP

#include "ALGraph.h"
#include "GraphDetail.h"
#include <iostream>
#include <queue>

// ---------- DirectedALGraph ----------

template<typename T>
void DirectedALGraph<T>::freeEdges() {
    for (int i = 0; i < vexNum_; ++i) {
        EdgeNode<T>* p = vertices_[i].firstEdge_;
        while (p) {
            EdgeNode<T>* tmp = p;
            p = p->next_;
            delete tmp;
        }
        vertices_[i].firstEdge_ = nullptr;
    }
}

template<typename T>
void DirectedALGraph<T>::buildFromMatrix(const std::vector<std::vector<T>>& matrix) {
    edgeNum_ = 0;
    for (int i = 0; i < vexNum_; ++i) {
        for (int j = 0; j < vexNum_; ++j) {
            if (matrix[i][j] != 0) {
                ++edgeNum_;
                // 头插法加入边表节点
                // 对于邻接表，头节点之后的边表节点，其链接顺序是无关紧要的
                vertices_[i].firstEdge_ = new EdgeNode<T>(j, matrix[i][j], vertices_[i].firstEdge_);
            }
        }
    }
}

template<typename T>
DirectedALGraph<T>::DirectedALGraph(int n, const std::vector<std::vector<T>>& matrix)
    : vexNum_(n), vertices_(n) {
    // 构建头节点数组
    for (int i = 0; i < vexNum_; ++i) {
        vertices_[i].data_ = i;
    }
    // 之后如果有边，就用头插法加入到头节点后面
    buildFromMatrix(matrix);
}

template<typename T>
DirectedALGraph<T>::DirectedALGraph(const std::string& csvFile)
    : vexNum_(0) {
    std::vector<std::vector<T>> matrix = graph_detail::loadMatrixFromCsv<T>(csvFile, vexNum_);
    vertices_.resize(vexNum_);
    for (int i = 0; i < vexNum_; ++i) {
        vertices_[i].data_ = i;
    }
    buildFromMatrix(matrix);
}

template<typename T>
DirectedALGraph<T>::~DirectedALGraph() {
    freeEdges();
}

template<typename T>
void DirectedALGraph<T>::print() {
    std::cout << "DirectedALGraph (" << vexNum_ << " vertices, " << edgeNum_ << " edges):" << std::endl;
    for (int i = 0; i < vexNum_; ++i) {
        std::cout << "V" << i << ": ";
        EdgeNode<T>* p = vertices_[i].firstEdge_;
        while (p) {
            std::cout << "-> V" << p->adjVex_ << "(w=" << p->weight_ << ") ";
            p = p->next_;
        }
        std::cout << std::endl;
    }
}

template<typename T>
std::vector<int> DirectedALGraph<T>::bfs() {
    std::vector<bool> visited(vexNum_, false);
    std::queue<int> queue;
    std::vector<int> ans;

    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
        int t = queue.front();
        ans.push_back(t);
        visited[t] = true;
        queue.pop();

        EdgeNode<T>* p = vertices_[t].firstEdge_;

        while (p != nullptr) {
            int v = p->adjVex_;
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
            p = p->next_;
        }
    }
    return ans;
}

template<typename T>
void DirectedALGraph<T>::dfsHelper(int v, std::vector<bool> &visited, std::vector<int> &ans) {
    visited[v] = true;
    ans.push_back(v);

    EdgeNode<T>* p = vertices_[v].firstEdge_;
    while (p != nullptr) {
        int t = p->adjVex_;
        if (!visited[t]) {
            dfsHelper(t, visited, ans);
        }
        p = p->next_;
    }
}

template<typename T>
std::vector<int> DirectedALGraph<T>::dfs() {
    std::vector<bool> visited(vexNum_, false);
    std::vector<int> ans;

    dfsHelper(0, visited, ans);
    return ans;
}

// ---------- UndirectedALGraph ----------

template<typename T>
void UndirectedALGraph<T>::freeEdges() {
    for (int i = 0; i < vexNum_; ++i) {
        EdgeNode<T>* p = vertices_[i].firstEdge_;
        while (p) {
            EdgeNode<T>* tmp = p;
            p = p->next_;
            delete tmp;
        }
        vertices_[i].firstEdge_ = nullptr;
    }
}

template<typename T>
void UndirectedALGraph<T>::buildFromMatrix(const std::vector<std::vector<T>>& matrix) {
    edgeNum_ = 0;
    for (int i = 0; i < vexNum_; ++i) {
        // 无向图只访问上三角部分
        for (int j = i + 1; j < vexNum_; ++j) {
            if (matrix[i][j] != 0) {
                ++edgeNum_;
                vertices_[i].firstEdge_ = new EdgeNode<T>(j, matrix[i][j], vertices_[i].firstEdge_);
                vertices_[j].firstEdge_ = new EdgeNode<T>(i, matrix[j][i], vertices_[j].firstEdge_);
            }
        }
    }
}

template<typename T>
UndirectedALGraph<T>::UndirectedALGraph(int n, const std::vector<std::vector<T>>& matrix)
    : vexNum_(n), vertices_(n) {
    for (int i = 0; i < vexNum_; ++i) {
        vertices_[i].data_ = i;
    }
    buildFromMatrix(matrix);
}

template<typename T>
UndirectedALGraph<T>::UndirectedALGraph(const std::string& csvFile)
    : vexNum_(0) {
    std::vector<std::vector<T>> matrix = graph_detail::loadMatrixFromCsv<T>(csvFile, vexNum_);
    vertices_.resize(vexNum_);
    for (int i = 0; i < vexNum_; ++i) {
        vertices_[i].data_ = i;
    }
    buildFromMatrix(matrix);
}

template<typename T>
UndirectedALGraph<T>::~UndirectedALGraph() {
    freeEdges();
}

template<typename T>
void UndirectedALGraph<T>::print() {
    std::cout << "UndirectedALGraph (" << vexNum_ << " vertices, " << edgeNum_ << " edges):" << std::endl;
    for (int i = 0; i < vexNum_; ++i) {
        std::cout << "V" << i << ": ";
        EdgeNode<T>* p = vertices_[i].firstEdge_;
        while (p) {
            std::cout << "-> V" << p->adjVex_ << "(w=" << p->weight_ << ") ";
            p = p->next_;
        }
        std::cout << std::endl;
    }
}

template<typename T>
std::vector<int> UndirectedALGraph<T>::bfs() {
    std::vector<bool> visited(vexNum_, false);
    std::queue<int> queue;
    std::vector<int> ans;

    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
        int t = queue.front();
        ans.push_back(t);
        visited[t] = true;
        queue.pop();

        EdgeNode<T>* p = vertices_[t].firstEdge_;

        while (p != nullptr) {
            int v = p->adjVex_;
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
            p = p->next_;
        }
    }
    return ans;
}

template<typename T>
void UndirectedALGraph<T>::dfsHelper(int v, std::vector<bool> &visited, std::vector<int> &ans) {
    visited[v] = true;
    ans.push_back(v);

    EdgeNode<T>* p = vertices_[v].firstEdge_;
    while (p != nullptr) {
        int t = p->adjVex_;
        if (!visited[t]) {
            dfsHelper(t, visited, ans);
        }
        p = p->next_;
    }
}

template<typename T>
std::vector<int> UndirectedALGraph<T>::dfs() {
    std::vector<bool> visited(vexNum_, false);
    std::vector<int> ans;

    dfsHelper(0, visited, ans);
    return ans;
}

#endif // DATA_STRUCTURE_SP26_ALGRAPH_TPP
