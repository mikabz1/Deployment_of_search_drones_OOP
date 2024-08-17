//
// Created by mbz on 04/07/2024.
//
#include "Node.h"
#include <iostream>
#ifndef SOLUTION2_DRONETREE_H
#define SOLUTION2_DRONETREE_H

class DroneTree{
private:
    Node *head;
    int treeSize;
    //recursive implementation of insert method.
    Node* insert(Node* root , Drone* drone);
    //recursive implementation of search method.
    Node* search(Node* root , Drone* drone);
    //recursive implementation of min method.
    static Node* min(Node* root);
    //recursive implementation of remove method.
    Node* remove(Node* root , Drone* drone);
    //recursive implementation of clear method.
    void clear(Node* root);
    //recursive implementation of print method.
    void printInOrder(Node* root);

public:
    /**
     * default constructor.
     * @param droneTree
     */
    DroneTree(): head(nullptr) , treeSize(0){};
    /**
     * first constructor.
     * @param droneTree
     */
    DroneTree(const DroneTree& droneTree);
    //operator =.
    DroneTree& operator=(const DroneTree& droneTree);
    ~DroneTree();
    /**
     * insert new node into the binary tree.
     * @param drone
     */
    void insert(Drone* drone);
    //search for drone in the tree.
    Node* search(Drone* drone);
    //get the minimum of the tree.
    Drone* min();
    //get the maximum of the tree.
    Drone* max();
    void remove(Drone* drone);
    void clear();
    void print();
    int size() const;
    Node* getHead(){
        return head;
    }
};

#endif //SOLUTION2_DRONETREE_H
