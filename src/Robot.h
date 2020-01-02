 #ifndef ROBOT_H
#define ROBOT_H
#include <stdbool.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "math.h"
#include "mbgoal.h"

using namespace std;


class Robot {
    private:
    int posX, posY, space;
    double vel;
    string name;
    vector <MBGoal> mbg;
    bool isMaxCapacity;

    public:
    //Robot(string, int, int);
   
    void setXY (int x, int y);
    void setSpeed(double vel);
    double getSpeed();
    int getMax();
    void setMax(int x);
    int getPosX (); 
    int getPosY (); 
    void setIsFull(bool x);
    bool getIsFull();
    void setName(string n);
    string getName();
 



};

void deleteRob(Robot current);
void printRoboInfo(Robot *current);
float dist_Rob_MBG(Robot *current, MBGoal *current1);
void updateRobot(Robot *current);
#endif