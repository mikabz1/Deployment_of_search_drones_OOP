#include "forest.h"
#include "functionHelper.h"
#include <sstream>

using namespace std;
using namespace forestNameSpace;
using namespace PointNameSpace;

int main(int argc , char *argv[]) {
    //check if there is exactly 3 file names in the program arguments.
    if(argc != 4 && argc != 5){
        help::printErrorNExit();
    }
    if(argc == 5){
        stringstream ss(argv[4]);
        int seed = 0;
        if(!(ss >> seed))help::printErrorNExit();
        srand(seed);
    } else{
        srand(time(nullptr));
    }
    int iterations = 0,iterationsCounter = 0;
    bool flag = false;
    //get the forest object from files.
    Forest *forest = help::fileManger(argv , iterations);
    //wile there is more iterations to do and a one of the drones did not reach yet the target cell.
    while (iterationsCounter < iterations && !flag){
        //move all drones location and update speed , best etc...
        help::moveLogic(*forest , flag);
        iterationsCounter++;
        if(flag)break;
    }
    //write results to the final file.
    if(!help::finalFile(argv[3] ,*forest , iterationsCounter)){
        help::printErrorNExit();
    }
    return 0;

}
