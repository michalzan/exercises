#ifndef EXERCISES_AVLTREE_H
#define EXERCISES_AVLTREE_H

#include "AvlNode.h"

class AvlTree {
public:
    AvlNode *root;

    void add(int number);

private:
    static void add(AvlNode* node, AvlNode* parent);

    static void rebalance(AvlNode* node, AvlNode* parent);
};


#endif //EXERCISES_AVLTREE_H
