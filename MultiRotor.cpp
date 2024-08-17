//
// Created by mbz on 06/07/2024.
//

#include "MultiRotor.h"
#include "functionHelper.h"
using namespace help;
ostream &MultiRotor::print(ostream &os) const {
    return os << "M " << floatingPoint(getLocation().getX()) << ' ' << floatingPoint(getLocation().getY()) << '\n';
}

void MultiRotor::setNewSpeed() {
    double a = 0.05 , b = 0.1 , c = 0;
    double r1 = (double)rand()/RAND_MAX;
    double r2 = (double)rand()/RAND_MAX;
    speed = speed*a + (personalBest - previousLocation)*r1*b + (globalBest - previousLocation)*r2*c;
}
