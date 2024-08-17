#include "forest.h"
using namespace forestNameSpace;
using namespace std;

int Forest::xMax = 0;
int Forest::xMin = 0;
int Forest::yMin = 0;
int Forest::yMax = 0;


/**
 * 2 argument constructor.
 * @param targetLocation
 * @param tree
 */
Forest::Forest(Point& targetLocation,DroneTree& tree):
        targetLocation(Forest::validatePoint(targetLocation)){
    //create the cells grid.
    arr = new Cell*[xMax + 1];
    for(int i = xMin ; i <= xMax ; i++){
        arr[i] = new Cell[yMax + 1];
        for(int j = yMin ; j <= yMax ; j++){
            arr[i][j].setPoint(i,j);
        }
    }
    droneTree = new DroneTree(tree);
}
/**
 * copy constructor.
 * @param forest
 */
Forest::Forest(const Forest &forest) {
    //copy the grid from forest.
    arr = new Cell*[xMax + 1];
    for(int i = xMin ; i <= xMax ; i++){
        arr[i] = new Cell[yMax + 1];
        for(int j = yMin ; j <= yMax ; j++){
            arr[i][j].setPoint(i,j);
        }
    }
    delete droneTree;
    droneTree = new DroneTree(*forest.droneTree);
}
/**
 * copy operator.(plus minus the same as copy constructor.
 * @param forest
 * @return this after the copy.
 */
Forest &Forest::operator=(const Forest &forest) {
    if(this == &forest){
        return *this;
    }
    else{
        for(int i = xMin; i < xMax ; i++){
            delete[] arr[i];
        }
        arr = new Cell*[xMax + 1];
        for(int i = xMin ; i <= xMax ; i++){
            arr[i] = new Cell[yMax + 1];
            for(int j = yMin ; j <= yMax ; j++){
                arr[i][j].setPoint(forest.getCellAt(i,j).getPoint());
            }
        }
        delete droneTree;
        droneTree = forest.droneTree;
        return *this;
    }
}
//destructor.
Forest::~Forest() {
    for(int i = xMin  ;i <= xMax ; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete droneTree;
}
//getters.
int Forest::operator()(int X, int Y) {
    return getDroneCounterAtCell(X , Y);
}
int Forest::getDroneCounterAtCell(int X, int Y) {
    return arr[X][Y].getDroneCounter();
}
Cell &Forest::getCellAt(int X, int Y) const {
    return arr[X][Y];
}
Point &Forest::getTargetLocation() {
    return targetLocation;
}
//check if a point is in the forest area(if its legit location).
Point &Forest::validatePoint(Point &p) {
    if(p.getX() > Forest::xMax)p.setX(Forest::xMax);
    if(p.getY() > Forest::yMax)p.setY(Forest::yMax);
    if(p.getX() < Forest::xMin)p.setX(Forest::xMin);
    if(p.getY() < Forest::yMin)p.setY(Forest::yMin);
    return p;
}

