#include "AvlNode.h"

AvlNode::AvlNode(int pValue) {
    depth = 1;
    value = pValue;
    left = nullptr;
    right = nullptr;
}