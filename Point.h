#include <cmath>

#ifndef SOLUTION_POINT_H
#define SOLUTION_POINT_H
namespace PointNameSpace{
    class Point{
    public:
        //default constructor.
        Point();
        //two arg constructor.
        Point(double X, double Y );
        //copy constructor.
        Point(const Point &p);
        //copy operator.
        Point& operator=(const Point& p);
        ~Point() = default;
        //sum X's and Y's.
        Point operator+(const Point& p) const;
        //subtract X's and Y's.
        Point operator-(const Point& p) const;
        //multiply the x and the y by a.
        Point operator*(double a) const;
        //getters and setters.
        double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);
        //calculate the distance between two point.
        static double distance(const Point& p1 , const Point& p2);
    private:
        double X , Y;
    };
}




#endif //SOLUTION_POINT_H
