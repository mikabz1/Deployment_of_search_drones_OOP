//
// Created by mbz on 06/07/2024.
//
#include "Drone.h"

#ifndef SOLUTION2_MULTIROTOR_H
#define SOLUTION2_MULTIROTOR_H

class MultiRotor : public Drone{
public:
    //default constructor.
    MultiRotor():Drone(){};
    MultiRotor(const MultiRotor& singleRotor): Drone(singleRotor){};
    MultiRotor(Point &location, const Point &speed) : Drone(location , speed){};
    //operator =.
    MultiRotor& operator=(const MultiRotor& singleRotor) = delete;
    ~MultiRotor() override = default;
    //override of print method from drone class.
    ostream& print(ostream& os) const override;
    //set the new speed of this drone.
    void setNewSpeed()override;


};



#endif //SOLUTION2_MULTIROTOR_H
