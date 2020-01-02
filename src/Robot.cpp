
#include "Robot.h"


void Robot::setXY (int x, int y){

    posX = x;
    posY = y;
}

void Robot::setName(string n){

    name = n;
}

void Robot::setMax(int x){

    space = x;
}
int Robot::getMax(){

    return space;
}
double Robot::getSpeed(){

    return vel;
}

void Robot::setSpeed(double velocity){
    vel = velocity;
}

int Robot::getPosX(){
    return posX;
}

int Robot::getPosY(){
    return posY;
}

string Robot::getName(){
    return name;
}

bool Robot::getIsFull(){
    return isMaxCapacity;
}
void Robot::setIsFull(bool x){
     isMaxCapacity = x;
}


void printRoboInfo(Robot*current){


    cout<<"Name: "<<current->getName()<<endl;
    cout<<"Position: ("<<current->getPosX()<<", "<<current->getPosY()<< ")"<<endl;
    cout<<"Storage Capacity: "<<current->getMax()<<endl;
    cout<<"Max speed: " <<current->getSpeed()<< endl;
    
   
  //  cout<<"Number of neighbors: "<<current->neighbors.size()<< endl;

}


float dist_Rob_MBG(Robot *current, MBGoal * current1){

    return sqrt( pow(current->getPosX()-current1->getPosX(), 2)+ pow(current->getPosY()-current1->getPosY(), 2));
}

void updateRobot(Robot *current){



int ans = 9;

while( ans!= 0){

cout<<"What would you like to change? (Type '0' when finished)"<<endl;
cout<<"1. Position"<<endl;
cout<<"2. Capacity"<<endl;
cout<<"3. Speed"<<endl;
cout<<"4. Name"<< endl;
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
        current->setMax(space);

       }
       break;

       case 3:
       {
           double speed;
        cout<< "New max velocity : ";
        cin>>speed;
        current->setSpeed(speed);
       }
       break;

      case 4:
      {
          string name;
          cout<<"New name for this mobile goal : ";
          cin>>name;
          current->setName(name);
      }
      break;
    }
}



>>>>>>> e5aae5aec5883a3b13295fede016bab26b33bc48
}