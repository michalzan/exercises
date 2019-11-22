#include "AvlTree.h"

void AvlTree::add(int number) {
    AvlNode node(number);
    if (root == nullptr) {
        root = &node;
        return;
    } else {
        add(&node, root);
    }
}

void AvlTree::add(AvlNode* node, AvlNode* parent) {
    if (node->value > parent->value) {
        if (parent->right == nullptr) {
            parent->right = node;
        } else {
            add(node, parent->right);
        }
    } else {
        if (parent->left == nullptr) {
            parent->left = node;
        } else {
            add(node, parent->left);
        }
    }
}

void AvlTree::rebalance(AvlNode* node, AvlNode* parent) {

}