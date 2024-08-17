#include "Point.h"
#include <iostream>
using namespace PointNameSpace;
using namespace std;

#ifndef SOLUTION_DRONE_H
#define SOLUTION_DRONE_H

class Drone{
public:
    static int globalId;//increase every new (non default) drone.
    static Point globalBest;//will store the closet to target location a drone was at.
    static int leaderId;//will store the id of the drone with the best 'personal best'.
    //default constructor.
    Drone();
    /**
    * copy constructor.
    * @param drone
    */
    Drone(const Drone& drone);
    /**
    * two argument constructor.
    * @param locationArg
    * @param speedArg
    */
    Drone(Point &location, const Point &speed);
    /**
    * operator = , copy all info from drone to this.
    * @param drone
    * @return this.
    */
    Drone& operator=(const Drone& drone);
    virtual ~Drone() = default;
    //operator << -> call print method.
    bool operator>(const Drone& drone)const;
    friend ostream& operator<<(ostream & os , Drone& drone);
    virtual ostream& print(ostream& os) const = 0;
    //getters and setters.
    int getID()const;
    const Point& getLocation()const;
    const Point & getSpeed() const;
    const Point& getPreviousLocation()const;
    const Point& getPersonalBest()const;
    void setPersonalBest(const Point& p);
    //move the drone to the new location and update the speed.
    void move();
protected:
    int id;
    Point location;
    Point speed;
    Point personalBest;
    Point previousLocation;
    //calculate new speed.
    virtual void setNewSpeed() = 0;
private:
    //calculate the new location.(speed + location = new location).
    void getNewLocation();
};
#endif //SOLUTION_DRONE_H
