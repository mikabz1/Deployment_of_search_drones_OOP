//
// Created by mbz on 04/07/2024.
//
#include "Drone.h"

#ifndef SOLUTION2_NODE_H
#define SOLUTION2_NODE_H

class Node{
public:
    Node *right , *left;
    Drone *data;
    //1 argument constructor.
    explicit Node(Drone* drone):right(nullptr) , left(nullptr) , data(drone){};
    //copy constructor.
    Node(const Node& node);
    //operator=.
    Node& operator=(const Node& node);
    //dest
    ~Node();
};

#endif //SOLUTION2_NODE_H
