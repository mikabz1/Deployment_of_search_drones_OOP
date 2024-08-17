//
// Created by mbz on 06/07/2024.
//
#include "Drone.h"
#include "SingleRotor.h"
#include "FixedWing.h"
#ifndef SOLUTION2_HYBRID_H
#define SOLUTION2_HYBRID_H

class Hybrid : public SingleRotor , public FixedWing{
public:
    //default constructor.
    Hybrid():Drone(){};
    Hybrid(const Hybrid& hybrid): Drone(hybrid){};
    Hybrid(Point &location, const Point &speed) : Drone(location , speed){};
    Hybrid& operator=(const Hybrid& hybrid) = delete;
    //operator =.
    ~Hybrid() override = default;
    //override of print method from drone class.
    ostream& print(ostream& os) const override;
    //set the new speed of this drone.
    void setNewSpeed()override;
};



#endif //SOLUTION2_HYBRID_H
