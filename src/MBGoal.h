
 #ifndef MBGOAL_H
#define MBGOAL_H
#include <stdbool.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "math.h"
#include <map>

using namespace std;

typedef int neighbors;
class MBGoal {
    private:
    int posX, posY;
    string name;
    bool isScored;
    

    public:
    //MBGoal();
   map<string, MBGoal*> neighbors;
    void setXY (int x, int y);
    void setScored(bool x);
    int getPosX (); 
    int getPosY (); 
    void setName(string n);
    string getName();
    bool getisScored();
    void setNeighbor(string name, MBGoal *current, map<string, MBGoal*> neighbor);
    bool checkIfNeighbor(MBGoal *current);

   


};
 //void *make_MBG(int x,int y, string name,int nBors);
//MBGoal *create_MB(string name, int x, int y, int neighbors);
// initializeMB (MBGoal *current, int x,int y, string name,int nBors);
//void setNeighbors(MBGoal current, int num);
//string getNeighbors(MBGoal current);
void deleteMB(MBGoal current);
void printInfo(MBGoal *current);
void findNearestMBG (MBGoal *current);
float dist_btw_MBGs(MBGoal *current, MBGoal * current1);
void updateMBGoal(MBGoal *current);

>>>>>>> e5aae5aec5883a3b13295fede016bab26b33bc48
#endif