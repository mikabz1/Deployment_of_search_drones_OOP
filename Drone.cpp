#include "forest.h"
#include "Drone.h"

using namespace forestNameSpace;
//init globalId.
int Drone::globalId = 0;
//init globalBest.
Point Drone::globalBest = Point(0,0);
//init leader drone id.
int Drone::leaderId = -1;
//default constructor.
Drone::Drone():id(globalId),location(),speed(),personalBest(location),previousLocation(){}
/**
 * two argument constructor.
 * @param locationArg
 * @param speedArg
 */
Drone::Drone(Point &locationArg,const Point &speedArg):id(globalId++),location(Forest::validatePoint(locationArg)) ,
                                                       speed(speedArg),personalBest(location),previousLocation(location){}
/**
 * copy constructor.
 * @param drone
 */
Drone::Drone(const Drone &drone):id(drone.getID()),location(drone.getLocation()),speed(drone.getSpeed()),
                                personalBest(location){}
/**
 * operator = , copy all info from drone to this.
 * @param drone
 * @return this.
 */
Drone &Drone::operator=(const Drone &drone) {
    if(this == &drone){
        return *this;
    }
    else{
        id = drone.getID();
        location = drone.getLocation();
        speed = drone.getSpeed();
        personalBest = drone.getPersonalBest();
        previousLocation = drone.previousLocation;
        return *this;
    }
}
//check if this id is grater the other drone id.
bool Drone::operator>(const Drone &drone)const{
    return (id > drone.id);
}
//getters and setters.
int Drone::getID() const {
    return id;
}
const Point &Drone::getLocation() const {
    return location;
}
 const Point & Drone::getSpeed() const {
    return speed;
}
const Point &Drone::getPreviousLocation() const {
    return previousLocation;
}
const Point& Drone::getPersonalBest() const {
    return personalBest;
}
void Drone::setPersonalBest(const Point &p) {
    personalBest = p;
}
//calculate the new location.(speed + location = new location).
void Drone::getNewLocation() {
    Point temp = speed + location;
    previousLocation = location;
    location = Forest::validatePoint(temp);
}
//move the drone to the new location and update the speed.
void Drone::move() {
    getNewLocation();
    setNewSpeed();
}
//operator << -> call print method.
ostream &operator<<(ostream &os, Drone &drone) {

    return drone.print(os);
}


