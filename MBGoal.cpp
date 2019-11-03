#include "mbgoal.h"
#include <vector>


/*MBGoal::MBGoal initializeMB( int x, int y, string name, int nBors){

current->setXY(x,y);
current->setName(name);
current->setScored(false);


for(int i =0; i<nBors;i++){
    current->neighbors.push_back({0});
}

}
*/

void * make_MBG(int x, int y, string name, int nBors){

    MBGoal *MBG;
    MBG = new MBGoal;

    MBG->setXY(x,y);
MBG->setName(name);
MBG->setScored(false);

for(int i =0; i<nBors;i++){
    MBG->neighbors.push_back(0);
}


return MBG;
}



void MBGoal::setXY (int x, int y){

    posX = x;
    posY = y;
}

void MBGoal::setName(string n){

    name = n;
}

void MBGoal::setScored(bool x){

    isScored = x;
}


int MBGoal::getPosX(){
    return posX;
}

int MBGoal::getPosY(){
    return posY;
}

string MBGoal::getName(){
    return name;
}

bool MBGoal::getisScored(){
    return isScored;
}

void printInfo(MBGoal *current){

    cout<<"Name: "<<current->getName()<<endl;
    cout<<"Position: ("<<current->getPosX()<<", "<<current->getPosY()<< ")"<<endl;
    cout<<"Scored?: "<<current->getisScored()<<endl;
    cout<<"Number of neighbors: "<<current->neighbors.size()<< endl;

}