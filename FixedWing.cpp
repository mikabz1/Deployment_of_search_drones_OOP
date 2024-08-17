//
// Created by mbz on 06/07/2024.
//

#include "FixedWing.h"
#include "functionHelper.h"
using namespace help;
ostream &FixedWing::print(ostream &os) const {
    return os << "W " << floatingPoint(getLocation().getX()) << ' ' << floatingPoint(getLocation().getY()) << '\n';
}

void FixedWing::setNewSpeed() {
    double a = 0.25;
    double r1 = (double)rand()/RAND_MAX;
    double r2 = (double)rand()/RAND_MAX;
    speed = speed*a + (personalBest - previousLocation)*r1 + (globalBest - previousLocation)*r2;
}
