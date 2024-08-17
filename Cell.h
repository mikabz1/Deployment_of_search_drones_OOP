#include "Point.h"
#include <iostream>
using namespace PointNameSpace;

#ifndef SOLUTION_CELL_H
#define SOLUTION_CELL_H
namespace forestCell{
    class Cell{
    public:
        //default constructor.
        Cell();
        /**
        * copy constructor.
        * @param cell to be copied.
        */
        Cell(const Cell& cell);
        /**
        * operator = .
        * @param cell to be compare.
        * @return a cell.
        */
        Cell& operator=(const Cell &cell);
        //default destructor.
        ~Cell();
        /**
        * @return the point of 'this' cell.
        */
        const Point& getPoint() const;
        /**
        * @return number of drone in 'this' cell.
        */
        int getDroneCounter()const;
        //pre operators increment and decrement , will adjust number of drones that are in 'this' cell.
        Cell operator++();
        Cell operator--();
        //post operators increment and decrement , will adjust number of drones that are in 'this' cell.
        Cell operator++(int);
        Cell operator--(int);
        /**
        * set this cell's point by getting x and y.
        * @param X
        * @param Y
        */
        void setPoint(int X , int Y);
        /**
        * set this cell's point by getting a point object.
        * @param p
        */
        void setPoint(const Point& p);
    private:
        Point point;
        int droneCounter;
    };
}
#endif //SOLUTION_CELL_H
