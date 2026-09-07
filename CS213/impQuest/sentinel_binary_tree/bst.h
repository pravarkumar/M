#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
};

class SentinelBST {
private:
    Node* root;
    Node* sentinel;

    // Helpers for the implementation.
    Node* searchNode(int key) const;
    Node* minimumNode(Node* x) const;
    Node* maximumNode(Node* x) const;
    Node* successorNode(Node* x) const;
    Node* predecessorNode(Node* x) const;

    void transplant(Node* u, Node* v);
    void clearSubtree(Node* x);
    int heightNode(Node* x) const;
    void inorderNode(Node* x, std::vector<int>& out) const;

public:
    SentinelBST();
    ~SentinelBST();

    void insert(int key);
    void erase(int key);

    bool search(int key) const;

    bool minimum(int& result) const;
    bool maximum(int& result) const;
    bool successor(int key, int& result) const;
    bool predecessor(int key, int& result) const;

    int height() const;
    std::vector<int> inorder() const;

    void clear();
};

#endif
