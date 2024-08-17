#include <string>
#include "forest.h"

#ifndef SOLUTION_FILEFUNCIONHELPER_H
#define SOLUTION_FILEFUNCIONHELPER_H

using namespace forestNameSpace;
using namespace std;
namespace help{
    /**
     * this function handle the first file(config).
     * @param fileName to read from.
     * @param targetLocation ref to update(get the info from the file).
     * @param iterations ref to update(get info from file).
     * forest size.
     * @param xMin
     * @param yMin
     * @param xMax
     * @param yMax
     * @return true if success else false.
     */
    bool configFile(const string& fileName,Point& targetLocation,int& iterations,int&xMin,int& yMin,int& xMax,int& yMax );
    /**
     * this function handle the second file.
     * at the end we get the number of drone to create.
     * @param fileName
     */
    DroneTree* initFile(const string& fileName);
    /**
     * this function manage the process of retrieving and using the data from
     * the config and init files.
     * @param argv the file name array(from the main).
     * @param iterationsArg ref to be update.(number of iteration)
     * @return forest object with target point, drone array already initialized.
     */
    Forest* fileManger(char** argv,int& iterationArg);
    /**
     * this function responsible of moving the drones and updating all drones data.
     * @param forest
     * @param flag true if a drone cross the target point.
     */
    void moveLogic(Forest& forest , bool& flag);
    /**
      * this function handle the final file writing process.
      * @param fileName
      * @param forest
      * @param iterations
      * @return true if success.
      */
    bool finalFile(const string& fileName , Forest& forest , int iterations);
    //this function handel the printing precision of the final file.
    string floatingPoint(double num);
    void printErrorNExit();
    //return new instance of a drone by his drone type.
    Drone* getDronePtr(char droneType , Point& location , Point& speed);
    /**
     * this function is recursive.
     * in the end is moving all the drone.
     * @param root
     * @param targetLocation
     * @param flag
     * @param forest
     * @param tempGlobal
     */
    void moveHelper(Node* root , Point& targetLocation , bool& flag , Forest& forest , Point& tempGlobal);
    /**
     * this function is recursive.
     * in the end the function update the global best.
     * @param root
     * @param tempGlobal
     * @param targetLocation
     */
    void setGlobalBest(Node* root , Point& tempGlobal , Point& targetLocation);
    /**
     * this function is recursive.
     * in the end this function set the number of drones in every forest cell.
     * @param root
     * @param forest
     * @param droneTree
     */
    void setForestCells(Node* root , Forest& forest , DroneTree& droneTree);
    //print into the file all drones.
    void finalFileHelper(Node* root , ofstream& file);
}
#endif //SOLUTION_FILEFUNCIONHELPER_H
