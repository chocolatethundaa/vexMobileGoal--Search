#include "mbgoal.h"
#include <vector>
#include <iterator>
#include "float.h"


/*MBGoal:: MBGoal (string name, int posX, int posY){


    cout<< "Constructor with 3 parameters is being used"<< endl;

    this->name = name;
    this->posX = posX;
    this->posY = posY;

    isScored = false;
}*/
/*MBGoal::MBGoal initializeMB( int x, int y, string name, int nBors){

current->setXY(x,y);
current->setName(name);
current->setScored(false);


for(int i =0; i<nBors;i++){
    current->neighbors.push_back({0});
}

}
*/

/*void * make_MBG(int x, int y, string name, int nBors){

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
*/

void MBGoal :: setNeighbor(string name, MBGoal *current,map<string, MBGoal*> neighbor){

map<string, MBGoal*> :: iterator it = neighbor.begin();
    while(it!= neighbor.end()){
        if(current->neighbors.count(it->first)<1){
            current->neighbors.insert(pair<string,MBGoal*>(it->first,it->second));
           it->second->neighbors.insert(pair<string,MBGoal*>(name,current));
           
        }
        it++;
    }

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

void printInfo(MBGoal*current){

map<string, MBGoal*> :: iterator it = current->neighbors.begin();
    cout<<"Name: "<<current->getName()<<endl;
    cout<<"Position: ("<<current->getPosX()<<", "<<current->getPosY()<< ")"<<endl;
    cout<<"Scored?: "<<current->getisScored()<<endl;
    while(it!= current->neighbors.end()){
        cout<<"Neighbors are: "<<it->first<< endl;
        it++;
    }
  //  cout<<"Number of neighbors: "<<current->neighbors.size()<< endl;

}

void findNearestMBG (MBGoal *current){
map<string, MBGoal*> :: iterator it = current->neighbors.begin();

double minDis = DBL_MAX;
string name;
    while(it!= current->neighbors.end()){
        double dis =dist_btw_MBGs(current, it->second);

        if(minDis>dis){ 
            minDis= dis; 
            name = it->first;
            }
            it++;
    }

    cout<< "Closest MB is "<< name <<endl;
    cout<< "With a distance of "<< minDis<<endl; 
}
float dist_btw_MBGs(MBGoal *current, MBGoal * current1){

    return sqrt( pow(current->getPosX()-current1->getPosX(), 2)+ pow(current->getPosY()-current1->getPosY(), 2));
}