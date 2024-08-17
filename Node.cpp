//
// Created by mbz on 04/07/2024.
//

#include "Node.h"
//copy constructor.
Node::Node(const Node &node) {
    right = node.right;
    left = node.left;
    data = node.data;
}
//operator=.
Node &Node::operator=(const Node &node) {
    if(this == &node){
        return *this;
    }
    right = node.right;
    left = node.left;
    data = node.data;
    return *this;
}

Node::~Node() {
    delete data;
}
