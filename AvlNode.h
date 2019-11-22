#ifndef EXERCISES_AVLNODE_H
#define EXERCISES_AVLNODE_H

using namespace std;

class AvlNode {
public:
    int depth;
    int value;
    AvlNode *left;
    AvlNode *right;

    AvlNode(int pValue);
};


#endif //EXERCISES_AVLNODE_H
