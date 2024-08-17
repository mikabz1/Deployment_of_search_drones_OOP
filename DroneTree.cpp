#include "DroneTree.h"
/**
 * first constructor.
 * @param droneTree
 */
DroneTree::DroneTree(const DroneTree &droneTree) {
    head = droneTree.head;
    treeSize = droneTree.treeSize;
}
//operator =.
DroneTree &DroneTree::operator=(const DroneTree &droneTree) {
    if(this == &droneTree){
        return *this;
    }
    head = droneTree.head;
    treeSize = droneTree.treeSize;
    return *this;
}

DroneTree::~DroneTree() {
    clear();
}

/**
 * insert new node into the binary tree.
 * @param drone
 */
void DroneTree::insert(Drone *drone) {
    if(drone == nullptr)return;
    head = insert(head,drone);
}
//recursive implementation of insert method.
Node *DroneTree::insert(Node *root, Drone *drone) {
    if(!root){
        treeSize++;
        return new Node(drone);
    }
    //if the drone needs to go 'left'.
    else if(!(*drone > *root->data)){
        root->left = insert(root->left , drone);
    }
    //if the drone needs to go 'right'.
    else if(*drone > *root->data){
        root->right = insert(root->right , drone);
    }
    return root;
}
//search for drone in the tree.
Node* DroneTree::search(Drone *drone) {
    if(drone == nullptr)return nullptr;
    Node* tempHead = head;
    return search(tempHead , drone);
}
//recursive implementation of search method.
Node *DroneTree::search(Node *root, Drone *drone) {
    //if the root is null of the root is the object to find.
    if(root == nullptr || root->data->getID() == drone->getID())return root;
    //if is bigger.
    if(*drone > *root->data)return search(root->right , drone);
    //if is smaller.
    else return search(root->left , drone);
}
//get the minimum of the tree.
Drone *DroneTree::min() {
    if (treeSize == 0)return nullptr;
    Node *tempHead = head;
    Node *result = min(tempHead);
    return result->data;
}
//recursive implementation of min method.
Node *DroneTree::min(Node *root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
//get the maximum of the tree.
Drone *DroneTree::max() {
    if (treeSize == 0)return nullptr;
    Node *tempHead = head;
    while (tempHead->right != nullptr) {
        tempHead = tempHead->right;
    }
    return tempHead->data;
}

void DroneTree::remove(Drone *drone) {
    head = remove(head , drone);
}
//recursive implementation of remove method.
Node *DroneTree::remove(Node *root , Drone* drone) {
    if(root == nullptr)return root;
    if(*drone > *root->data){//if is bigger -> search in the right.
        root->right = remove(root->right , drone);
    }//else search in the left.
    else if(!(*drone > *root->data)){
        root->left = remove(root->left , drone);
    }
    else{//if is equal.
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            treeSize--;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            treeSize--;
            return temp;
        }//if he has two 'children'.
        *root->data = *min(root->right)->data;//update data with the following node.
        root->right = remove(root->right , root->data);//remove the following node from the right.
        return root;
    }
    return root;
}

void DroneTree::clear() {
    clear(head);
    head = nullptr;
    treeSize = 0;
}
//recursive implementation of clear method.
void DroneTree::clear(Node *root) {
    if(root){
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

void DroneTree::print() {
    Node* tempHead = head;
    printInOrder(tempHead);
}
//recursive implementation of print method.
void DroneTree::printInOrder(Node *root) {
    if(root){
        printInOrder(root->left);
        std::cout << *root->data;
        printInOrder(root->left);
    }
}

int DroneTree::size() const {
    return treeSize;
}


