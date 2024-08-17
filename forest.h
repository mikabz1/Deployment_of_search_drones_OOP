#include "Cell.h"
#include "Drone.h"
#include "DroneTree.h"

#ifndef SOLUTION_FOREST_H
#define SOLUTION_FOREST_H

using namespace forestCell;

namespace forestNameSpace{
    class Forest{
    public:
        static int xMin , xMax , yMin , yMax;//store the forest size.
        /**
         * 2 argument constructor.
         * @param targetLocation
         * @param tree
         */
        Forest(Point& targetLocation,DroneTree& tree);
        /**
        * copy constructor.
        * @param forest
        */
        Forest(const Forest& forest);
        /**
        * copy operator.(plus minus the same as copy constructor.
        * @param forest
        * @return this after the copy.
        */
        Forest& operator=(const Forest& forest);
        //destructor.
        ~Forest();
        //getters.
        int operator()(int X , int Y);
        int getDroneCounterAtCell(int X , int Y);
        Cell& getCellAt(int X , int Y)const;
        DroneTree* getDroneTree(){
            return droneTree;
        }
        Point& getTargetLocation();
        //check if a point is in the forest area(if its legit location).
        static Point& validatePoint(Point& p);
    private:
        Cell** arr;//cell grid.
        DroneTree* droneTree;
        Point targetLocation;
    };
}
#endif //SOLUTION_FOREST_H
