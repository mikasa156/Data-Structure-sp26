#ifndef DATA_STRUCTURE_SP26_ALGRAPH_TPP
#define DATA_STRUCTURE_SP26_ALGRAPH_TPP

#include "ALGraph.h"
#include "GraphDetail.h"
#include <iostream>

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
                vertices_[i].firstEdge_ = new EdgeNode<T>(j, matrix[i][j], vertices_[i].firstEdge_);
            }
        }
    }
}

template<typename T>
DirectedALGraph<T>::DirectedALGraph(int n, const std::vector<std::vector<T>>& matrix)
    : vexNum_(n), vertices_(n) {
    for (int i = 0; i < vexNum_; ++i) {
        vertices_[i].data_ = i;
    }
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

#endif // DATA_STRUCTURE_SP26_ALGRAPH_TPP
