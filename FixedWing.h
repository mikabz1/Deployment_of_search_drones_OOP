//
// Created by mbz on 06/07/2024.
//
#include "Drone.h"

#ifndef SOLUTION2_FIXEDWING_H
#define SOLUTION2_FIXEDWING_H

class FixedWing : virtual public Drone{
public:
    //default constructor.
    FixedWing():Drone(){};
    FixedWing(const FixedWing& singleRotor): Drone(singleRotor){};
    FixedWing(Point &location, const Point &speed) : Drone(location , speed){};
    //operator =.
    FixedWing& operator=(const FixedWing& singleRotor) = delete;
    ~FixedWing() override = default;
    //override of print method from drone class.
    ostream& print(ostream& os) const override;
    //set the new speed of this drone.
    void setNewSpeed()override;
};

#endif //SOLUTION2_FIXEDWING_H
