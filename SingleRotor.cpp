//
// Created by mbz on 06/07/2024.
//

#include "SingleRotor.h"
#include "functionHelper.h"
using namespace help;
ostream &SingleRotor::print(ostream &os) const {
    return os << "S " << floatingPoint(getLocation().getX()) << ' ' << floatingPoint(getLocation().getY()) << '\n';
}

void SingleRotor::setNewSpeed() {
    double a = 0.01 , b = -0.1 , c = -0.25;
    double r1 = (double)rand()/RAND_MAX;
    double r2 = (double)rand()/RAND_MAX;
    speed = speed*a + (personalBest - previousLocation)*r1*b + (globalBest - previousLocation)*r2*c;
}
