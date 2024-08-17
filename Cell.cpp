#include "Cell.h"
using namespace forestCell;

//defaults constructor.
Cell::Cell(): point(Point()) , droneCounter(0) {}
/**
 * copy constructor.
 * @param cell to be copied.
 */
Cell::Cell(const Cell &cell): point(Point(cell.getPoint())) , droneCounter(cell.getDroneCounter()){}
/**
 * operator = .
 * @param cell to be compare.
 * @return a cell.
 */
Cell &Cell::operator=(const Cell &cell) {
    if(this == &cell){
        return *this;
    }
    else{
        point = cell.getPoint();
        droneCounter = cell.getDroneCounter();
        return *this;
    }
}
//default destructor.
Cell::~Cell() = default;
/**
 * @return number of drone in 'this' cell.
 */
int Cell::getDroneCounter()const {
    return droneCounter;
}
/**
 * @return the point of 'this' cell.
 */
const Point &Cell::getPoint() const {
    return point;
}
//pre operators increment and decrement , will adjust number of drones that are in 'this' cell.
Cell Cell::operator++() {
    droneCounter++;
    return *this;
}
Cell Cell::operator--() {
    droneCounter--;
    return *this;
}
//post operators increment and decrement , will adjust number of drones that are in 'this' cell.
Cell Cell::operator++(int) {
    Cell copy(*this);
    ++(*this);
    return copy;
}
Cell Cell::operator--(int) {
    Cell temp = *this;
    --(*this);
    return temp;
}
/**
 * set this cell's point by getting x and y.
 * @param X
 * @param Y
 */
void Cell::setPoint(int X , int Y) {
    point.setX((float)X);
    point.setY((float)Y);
}
/**
 * set this cell's point by getting a point object.
 * @param p
 */
void Cell::setPoint(const Point &p) {
    setPoint((int) p.getX() , (int)p.getY());
}