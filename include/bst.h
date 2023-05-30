// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>

template <typename T>
class BST {
 private:
    struct Node {
        T val;
        unsigned int count;
        Node* l;
        Node* r;
    };
    Node* root = nullptr;
    int searchNodeTree(Node* root, const T& value) {
        if (root == nullptr) {
            return 0;
        } else if (root->val > value) {
            return searchNodeTree(root->l, value);
        } else if (root->val < value) {
            return searchNodeTree(root->r, value);
        } else {
            return root->count;
        }
        return 0;
    }
    int getDepthTree(Node* root) {
        if (root == nullptr)
            return 0;
        int rDepth = getDepthTree(root->r),
            lDepth = getDepthTree(root->l);
        return (lDepth > rDepth) ? lDepth + 1 : rDepth + 1;
    }
    Node* newNodeTree(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->val = value;
            root->count = 1;
            root->l = root->r = nullptr;
        } else if (root->val < value) {
            root->r = newNodeTree(root->r, value);
        } else if (root->val > value) {
            root->l = newNodeTree(root->l, value);
        } else {
            root->count+=1;
        }
        return root;
    }

 public:
    int search(const T& value) {
        return searchNodeTree(root, value);
    }
    int depth() {
        return getDepthTree(root) - 1;
    }
    void newNode(const T& value) {
        root = newNodeTree(root, value);
    }
};

#endif  // INCLUDE_BST_H_
