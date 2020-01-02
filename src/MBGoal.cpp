
#include "mbgoal.h"
#include <vector>
#include <iterator>
#include "float.h"



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

void updateMBGoal(MBGoal *current){



int ans = 9;

while( ans!= 0){

cout<<"What would you like to change? (Type '0' when finished)"<<endl;
cout<<"1. Position"<<endl;
cout<<"2. Neigbors"<<endl;
cout<<"3. Name"<<endl;
cin>>ans;
    switch(ans){

        case 1:
        {
            int x,y;
         cout << "New starting x position of : ";
         cin>> x;
         cout<<endl;
         cout << "New starting y position of : ";
         cin>> y;
         cout<<endl;
         current->setXY(x,y);
        }
        break;
       
       case 2:
       {
           int space;
        cout<< "New capacity size : ";
        cin>>space;
       // current->setMax(space);

       }
       break;


      case 3:
      {
          string name;
          cout<<"New name for this mobile goal : ";
          cin>>name;
          current->setName(name);
      }
      break;
    }
}




}