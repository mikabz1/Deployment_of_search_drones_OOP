#include "functionHelper.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "MultiRotor.h"
#include "Hybrid.h"

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
bool help::configFile(const string& fileName,Point &targetLocation,int& iterations,int&xMin,int& yMin,int& xMax,int& yMax) {
    ifstream inputFile(fileName);
    if(!inputFile.is_open())return false;
    string line1,line2,line3,extra;
    if(!getline(inputFile , line1))return false;
    if(!getline(inputFile , line2))return false;
    if(!getline(inputFile , line3))return false;
    //if there is moore than 2 line in the file.
    if(getline(inputFile , extra))return false;
    inputFile.close();

    //get first line.
    stringstream ss1(line1);
    if(!(ss1 >> xMin) || !(ss1 >> yMin) || !(ss1 >> xMax) || !(ss1 >> yMax))return false;
    if(xMax <= xMin || yMax <= yMin)return false;

    //get second line.
    double X , Y;
    stringstream ss(line2);
    //convert from string to double.
    if(!(ss >> X) || !(ss >> Y))return false;
    if(ss >> extra)return false;
    if(X < xMin || X > xMax || Y < yMin || Y > yMax)return false;
    //update targetLocation ref.
    targetLocation.setX(floor(X));
    targetLocation.setY(floor(Y));

    if(line3.empty())return false;
    //check if its a number(int).
    for(char c : line3)if(!isdigit(c))return false;

    //update iteration ref.
    iterations = stoi(line3);
    return true;
}
/**
 * this function handle the second file.
 * at the end we get the number of drone to create.
 * @param fileName
 */
DroneTree* help::initFile(const string& fileName) {
    ifstream inputFile(fileName);
    if(!inputFile.is_open())printErrorNExit();

    string line1 , lines , extra;
    if(!getline(inputFile , line1))printErrorNExit();
    if(line1.empty())printErrorNExit();
    for(char c : line1)if(!isdigit(c))printErrorNExit();
    //update droneNumber ref.
    int droneNumber = stoi(line1);
    //create the drone tree on the heap.
    DroneTree *tree = new DroneTree();

    for(int i = 0 ; i < droneNumber;i++){
        //update the drone location and speed from the file.
        if(!getline(inputFile , lines))printErrorNExit();
        char droneType;
        double xLocation = 0, yLocation = 0, xSpeed = 0, ySpeed = 0;
        stringstream ss(lines);
        if(!(ss >>droneType) || !(ss >> xLocation) || !(ss >> yLocation) || !(ss >> xSpeed) || !(ss >> ySpeed))printErrorNExit();

        //if there is more than 4 number in a file line.
        if(ss >> extra)printErrorNExit();
        Point location = Point(xLocation,yLocation);
        Point speed = Point(xSpeed,ySpeed);
        //save drone into drone tree.
        tree->insert(getDronePtr(droneType , location , speed));
    }
    //if there is more line than droneNumber.
    if(getline(inputFile , extra))printErrorNExit();
    inputFile.close();
    return tree;
}
/**
 * this function manage the process of retrieving and using the data from
 * the config and init files.
 * @param argv the file name array(from the main).
 * @param iterationsArg ref to be update.(number of iteration)
 * @return forest object with target point, drone array already initialized.
 */
Forest* help::fileManger(char *argv[] , int& iterationsArg) {
    Point targetLocation;
    int xMin , xMax , yMin , yMax;
    //call the function that handle the first file.
    bool file1 = help::configFile(argv[1] , targetLocation , iterationsArg,xMin , yMin , xMax , yMax);
    if(!file1)printErrorNExit();
    Forest::xMax = xMax;
    Forest::yMax = yMax;
    Forest::xMin = xMin;
    Forest::yMin = yMin;
    //call the function that handle the second file.
    DroneTree *droneTree = help::initFile(argv[2]);
    //create the forest object from all the data from the two files.
    Forest *forest = new Forest(targetLocation , *droneTree);
    Point tempGlobal = forest->getDroneTree()->getHead()->data->getPersonalBest();
    Node* tempHead = forest->getDroneTree()->getHead();
    setGlobalBest(tempHead , tempGlobal , forest->getTargetLocation());
    tempHead = forest->getDroneTree()->getHead();
    setForestCells(tempHead , *forest ,*forest->getDroneTree());
    return forest;
}
/**
 * this function responsible of moving the drones and updating all drones data.
 * @param forest
 * @param flag true if a drone cross the target point.
 */
void help::moveLogic(Forest &forest , bool& flag) {
    Point tempGlobal = Drone::globalBest;
    moveHelper(forest.getDroneTree()->getHead(), forest.getTargetLocation() , flag , forest , tempGlobal);
    Drone::globalBest = tempGlobal;
}
/**
 * this function handle the final file writing process.
 * @param fileName
 * @param forest
 * @param iterations
 * @return true if success.
 */
bool help::finalFile(const string &fileName, Forest &forest , int iterations) {
    ofstream outputFile(fileName , ofstream::trunc);
    if(!outputFile.is_open())return false;
    outputFile << iterations << endl;
    finalFileHelper(forest.getDroneTree()->getHead(), outputFile );
    outputFile.close();
    return true;
}
//this function handel the printing precision of the final file.
string help::floatingPoint(double num) {
    ostringstream out;
    //if it's an int.
    if(floor(num) == num){
        out << fixed << setprecision(0) << num;
    }
    else{
        double temp = num*10;
        //if there is only one number after the floating point.
        if(floor(temp) == temp){
            out << fixed << setprecision(1) << num;
        }
        //if there is two or more number after the floating point.
        else{
            out << fixed << setprecision(2) << num;
        }
    }
    return out.str();
}
void help::printErrorNExit() {
    cerr << "Error; invalid input" << endl;
    exit(-1);
}
//return new instance of a drone by his drone type.
Drone* help::getDronePtr(char droneType, Point &location, Point &speed) {
    switch (droneType) {
        case 'S':{
            return  new SingleRotor(location , speed);
        }
        case 'M':{
            return new MultiRotor(location , speed);
        }
        case 'W':{
            return new FixedWing(location , speed);
        }
        case 'H':{
            return new Hybrid(location , speed);
        }
        default:
            printErrorNExit();
            return nullptr;
    }
}
/**
 * this function is recursive.
 * in the end is moving all the drone.
 * @param root
 * @param targetLocation
 * @param flag
 * @param forest
 * @param tempGlobal
 */
void help::moveHelper(Node *root , Point& targetLocation , bool& flag , Forest& forest , Point& tempGlobal) {
    if(!root || flag)return;
    moveHelper(root->left , targetLocation , flag , forest , tempGlobal);
    root->data->move();
    if(floor(root->data->getLocation().getX()) == targetLocation.getX() && floor(root->data->getLocation().getY()) == targetLocation.getY()){
        flag = true;
        return;
    }
    if(Point::distance(root->data->getPersonalBest() ,targetLocation) > Point::distance(root->data->getLocation(),targetLocation)){
        root->data->setPersonalBest(root->data->getLocation());
    }
    if(Point::distance(root->data->getPersonalBest(),targetLocation)<Point::distance(tempGlobal,targetLocation)){
        tempGlobal = root->data->getPersonalBest();
        Drone::leaderId = root->data->getID();
    }
    forest.getCellAt(floor(root->data->getPreviousLocation().getX()),floor(root->data->getPreviousLocation().getY()))--;
    forest.getCellAt(floor(root->data->getLocation().getX()),floor(root->data->getLocation().getY()))++;
    moveHelper(root->right , targetLocation , flag , forest , tempGlobal);
}
/**
 * this function is recursive.
 * in the end the function update the global best.
 * @param root
 * @param tempGlobal
 * @param targetLocation
 */
void help::setGlobalBest(Node* root , Point& tempGlobal , Point& targetLocation) {
    if(!root)return;
    setGlobalBest(root->left , tempGlobal , targetLocation);
    if(Point::distance(root->data->getPersonalBest(),targetLocation)<Point::distance(tempGlobal,targetLocation)){
        tempGlobal = root->data->getPersonalBest();
        Drone::leaderId = root->data->getID();
    }
    setGlobalBest(root->right , tempGlobal , targetLocation);
}
/**
 * this function is recursive.
 * in the end this function set the number of drones in every forest cell.
 * @param root
 * @param forest
 * @param droneTree
 */
void help::setForestCells(Node* root , Forest& forest , DroneTree& droneTree){
    if(!root)return;
    setForestCells(root->left , forest , droneTree);
    forest.getCellAt(floor(root->data->getLocation().getX()),floor(root->data->getLocation().getY()))++;
    setForestCells(root->right , forest , droneTree);
}
//print into the file all drones.
void help::finalFileHelper(Node *root,std::ofstream &file) {
    if(!root)return;
    finalFileHelper(root->left ,  file);
    file << *root->data;
    finalFileHelper(root->right ,  file);
}





