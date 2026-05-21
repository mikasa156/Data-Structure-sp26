//
// Created by yurino on 2026/5/21.
//

#ifndef TREES_BST_H
#define TREES_BST_H

#include <iostream>
#include <vector>

template<typename T>
class BST {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T data, Node* left, Node* right)
            : data(data), left(left), right(right) {}
    };
    Node* root;
    int size_;


    // 递归辅助函数：向以 node 为根的子树插入 data，返回是否成功插入
    bool addHelper(Node*& node, const T& data) {
        if (node == nullptr) {
            node = new Node(data, nullptr, nullptr);
            return true;
        }
        if (data < node->data) {
            return addHelper(node->left, data);
        } else if (node->data < data) {
            return addHelper(node->right, data);
        }
        // 如果相等，不做任何操作（不插入重复元素）
        return false;
    }

    void deleteXHelper(const T& x, Node*& node) {
        if (node == nullptr) {
            return;
        }
        if (node->data == x) {
            clear(node);
            node = nullptr;
            return;
        }
        deleteXHelper(x, node->left);
        deleteXHelper(x, node->right);
    }


    void exchangeHelper(Node* node) {
        if (node == nullptr) return;
        Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        exchangeHelper(node->left);
        exchangeHelper(node->right);
    }

    void printHelper(Node* node, int depth) const {
        if (node == nullptr) return;
        printHelper(node->right, depth + 1);
        for (int i = 0; i < depth; ++i) std::cout << "    ";
        std::cout << node->data << std::endl;
        printHelper(node->left, depth + 1);
    }

public:
    BST(): root(nullptr), size_(0) {}

    BST(const std::vector<T>& vec) : BST() {
        for (const auto& item : vec) {
            add(item);
        }
    }

    void add(const T& data) {
        if (addHelper(root, data)) {
            ++size_;
        }
    }

    void print() const {
        printHelper(root, 0);
    }

    int size() const {
        return size_;
    }

    void clear(Node* node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void deleteX(const T& x) {
        deleteXHelper(x, root);
    }

    void exchange() {
        exchangeHelper(root);
    }

};

#endif //TREES_BST_H
