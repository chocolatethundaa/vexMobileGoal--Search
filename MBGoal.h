 #ifndef MBGOAL_H
#define MBGOAL_H
#include <stdbool.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

typedef int neighbors;
class MBGoal {
    private:
    int posX, posY;
    string name;
    bool isScored;

    public:
    MBGoal(string, int, int);
   
    void setXY (int x, int y);
    void setScored(bool x);
    int getPosX (); 
    int getPosY (); 
    void setName(string n);
    string getName();
    bool getisScored();

   // vector <MBGoal*> neighbors;



};
 //void *make_MBG(int x,int y, string name,int nBors);
//MBGoal *create_MB(string name, int x, int y, int neighbors);
// initializeMB (MBGoal *current, int x,int y, string name,int nBors);
//void setNeighbors(MBGoal current, int num);
//string getNeighbors(MBGoal current);
void deleteMB(MBGoal current);
void printInfo(MBGoal *current);
float dist_btw_MBGs(MBGoal *current, MBGoal * current1);

#endif