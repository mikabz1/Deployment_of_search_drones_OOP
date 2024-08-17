#include "Point.h"

using namespace PointNameSpace;
//default constructor.
Point::Point(): X(0) , Y(0) {}
//two arg constructor.
Point::Point(double X, double Y): X(X) , Y(Y) {}
//copy constructor.
Point::Point(const Point &p): X(p.getX()) , Y(p.getY()){}
//copy operator.
Point &Point::operator=(const Point &p) {
    if(this == &p){
        return *this;
    }
    else{
        setX(p.getX());
        setY(p.getY());
        return *this;
    }
}
//sum X's and Y's.
Point Point::operator+(const Point &p) const{
    return {X + p.getX(), Y + p.getY()};
}
//subtract X's and Y's.
Point Point::operator-(const Point &p) const {
    return {X - p.getX(), Y - p.getY()};
}
//multiply the x and the y by a.
Point Point::operator*(double a) const {
    return {a*X , a*Y};
}
//getters and setters.
double Point::getX() const {return X;}
double Point::getY() const {return Y;}
void Point::setX(double x) {
    this->X = x;
}
void Point::setY(double y) {
    this->Y = y;
}
//calculate the distance between two point.
double Point::distance(const Point &p1, const Point &p2) {
    Point temp = p1 - p2;
    return sqrt(pow(temp.getX() , 2) + pow(temp.getY() , 2));
}



