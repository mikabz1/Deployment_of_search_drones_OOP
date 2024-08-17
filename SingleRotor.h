//
// Created by mbz on 06/07/2024.
//
#include "Drone.h"
//using namespace droneNamespace;

#ifndef SOLUTION2_SINGLEROTOR_H
#define SOLUTION2_SINGLEROTOR_H

class SingleRotor : virtual public Drone{
public:
    //default constructor.
    SingleRotor():Drone(){};
    SingleRotor(const SingleRotor& singleRotor): Drone(singleRotor){};
    SingleRotor(Point &location, const Point &speed) : Drone(location , speed){};
    //operator =.
    SingleRotor& operator=(const SingleRotor& singleRotor) = delete;
    ~SingleRotor() override = default;
    //override of print method from drone class.
    ostream& print(ostream& os) const override;
    //set the new speed of this drone.
    void setNewSpeed()override;
};

#endif //SOLUTION2_SINGLEROTOR_H
