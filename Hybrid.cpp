//
// Created by mbz on 06/07/2024.
//

#include "Hybrid.h"
#include "functionHelper.h"
using namespace help;
ostream &Hybrid::print(ostream &os) const {
    return os << "H " << floatingPoint(getLocation().getX()) << ' ' << floatingPoint(getLocation().getY()) << '\n';
}

void Hybrid::setNewSpeed() {
    SingleRotor::setNewSpeed();
}
