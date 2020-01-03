
#include<conio.h>
#include <iostream>
#include <string>
#include "mbgoal.h"
#include <map>
#include <vector>
#include "Robot.h"
#include <sstream>
#include "float.h"
#include "time.h"
using namespace std;

//global stctures and variables
vector <MBGoal*> MBGList;
vector <Robot*> BotList;
map<string, MBGoal*> mbg;
map<string, Robot*> rob;




//creating map for neighbors to add to each MBS
map<string, MBGoal*> initMap (string line){

   char split_char = ' ';
   istringstream split(line);
   vector<string> tokens;
   for (string each;getline(split, each, split_char); tokens.push_back(each));
   /*for(int i =0;i<tokens.size();i++){
     cout<<tokens[i]<<endl;
        }*/
  map<string, MBGoal*> N;
  for(int i =0; i<tokens.size(); i++){
      if(mbg.count(tokens[i])==1){
        N.insert(pair<string,MBGoal*>(tokens[i],mbg.at(tokens[i])));
      }
  }
  return N;
}
//function that finds the closest mbgoal to a robot **WILL NEED TO BE ALTERED WHEN GRAPH IS IMPLEMENTED
void findClosestMBG (Robot *current){
  auto it = mbg.begin();

  double minDis = DBL_MAX;
  string name = "";
   
    while(it!= mbg.end()){

      if(it->second->getisScored()== false){
      double dis =sqrt( pow(current->getPosX()-it->second->getPosX(), 2)+ pow(current->getPosY()-it->second->getPosY(), 2));

        if(minDis>dis){ 
            minDis= dis; 
            name = it->first;
            }
            it++;
    }
    }
        
  if(name == ""){

    cout<< "Either there are no mobile goals or all of them have been scored"<<endl;
  }
  else{
    cout<< "Closest MB is "<< name <<endl;
    cout<< "With a distance of "<< minDis<<endl; 
  }
    
}




int main(){

cout<<"The current field is flat and has the dimensions of 100 meters by 100 meters"<< endl;

//setting a preset
string preset;
cout<< "Would you like to use a preset field"<< endl;
cin>>preset;
if(preset == "yes"){
  string mb1 = "mb1";
  string mb2 = "mb2";
  string mb3 = "mb3";
  string vexRobot = "vexRobot";
  string array[3] = {mb1,mb2,mb3};
  srand(time(NULL));
  for(int i = 0; i<3; i++){
    MBGoal *MB;
    MB =  new MBGoal();
    MB->setName(array[i]);
    MB->setXY(rand() % 100,rand() % 100);
         
    MBGList.push_back(MB);
    mbg.insert(pair<string,MBGoal*>(array[i],MBGList[i]));
  }

  mbg.at(mb1)->neighbors.insert(pair<string,MBGoal*>(mb2,mbg.at(mb2)));
  mbg.at(mb1)->neighbors.insert(pair<string,MBGoal*>(mb3,mbg.at(mb3)));
  mbg.at(mb2)->neighbors.insert(pair<string,MBGoal*>(mb1,mbg.at(mb1)));
  mbg.at(mb3)->neighbors.insert(pair<string,MBGoal*>(mb1,mbg.at(mb1)));

  Robot *Bot;
  Bot =  new Robot();
  Bot->setName(vexRobot);
  Bot->setXY(rand() % 100,rand() % 100);
  Bot->setSpeed((double)(rand()%15 + 1));
  Bot->setMax(rand() % 2 +1);
         
  BotList.push_back(Bot);
  rob.insert(pair<string,Robot*>(vexRobot,BotList[0]));

}
//user input for setting up custom field
else{
      int num;
     cout<<"How many mobile Goals will there be?"<< endl;
     cin >> num;

      //setup mbgfield
     for (int i=0; i < num; i++){
         string name;
         int x,y;
        
         //int neighbors;
         cout<<"Name of mobile goal #"<<(i+1)<<" : ";
         cin>>name;
         cout<<endl;
         cout << "Starting x position of "<< name << " : ";
         cin>> x;
         cout<<endl;
         cout << "Starting y position of "<< name<< " : ";
         cin>> y;
         cout<<endl;
        MBGoal *MB;
         MB =  new MBGoal();
         MB->setName(name);
         MB->setXY(x,y);
         
        MBGList.push_back(MB);
        mbg.insert(pair<string,MBGoal*>(name,MBGList[i]));
         
     }

     //setNeighbors
     string finished;
      string currentMB;
      string setMB;
    while (finished != "yes"){

        cout << "Setting neighbors for: ";
        cin>> currentMB;
        cin.ignore();
        map<string, MBGoal*> Neighbors;
        getline(cin,setMB);

        Neighbors = initMap(setMB);


        mbg.at(currentMB)->setNeighbor(currentMB,mbg.at(currentMB), Neighbors);

        cout<<"completed setneighbors"<<endl;
        cout<< "Finished?" <<endl;
        cin>>finished;
        }


        cout<<"How many Robots will there be?"<< endl;
          cin >> num;

          for (int i=0; i < num; i++){
         string name;
         int x, y, space;
         double velocity;
         //int neighbors;
         cout<<"Name of robot #"<<(i+1)<<" : ";
         cin>>name;
         cout<<endl;
         cout << "Starting x position of "<< name << " : ";
         cin>> x;
         cout<<endl;
         cout << "Starting y position of "<< name<< " : ";
         cin>> y;
         cout<<endl;
         cout << "Storage capacity of the robot is "<< name<< " : ";
         cin>> space;
         cout<<endl;
         cout << "Max speed of the robot is "<< name<< " : ";
         cin>> velocity;
         cout<<endl;
        Robot *Bot;
         Bot =  new Robot();
         Bot->setName(name);
         Bot->setXY(x,y);
         Bot->setSpeed(velocity);
         Bot->setMax(space);
         
        BotList.push_back(Bot);
        rob.insert(pair<string,Robot*>(name,BotList[i]));
         
     }

}
   
//printing out field items
for(int i=0;i<MBGList.size(); i++){
         printInfo(MBGList[i]);
         cout<<endl;
          findNearestMBG(MBGList[i]) ;  
          cout<<endl;
     }

        auto it = rob.begin();

        while(it!= rob.end()){
       
            printRoboInfo(it->second);
            cout<<endl;
  
            it++;
}   



//switch statements to alter field or find different measurements
int switch1=8;

while(switch1!= 0){
cout<< "What would you like to find? "<< endl;
cout<< "1. Update a mobile goal?"<<endl;
cout<< "2. Update a Robot?"<<endl;
cout<< "3. Find distance between mobile goals?"<<endl;
cout<< "4. Find distance between Robot and mobile goal?"<<endl;
cout<< "5. Solve quickest way to score?"<< endl;
cout<< "0 to quit"<< endl;

cin>>switch1;


switch (switch1){
  //update a specific mbgoal
  case 1:
  {
      string name;
      string newName;
      cout<< "Which mobile goal would you like to update"<< endl;
      cin>>name;

      updateMBGoal(name, mbg.at(name));
      newName = mbg.at(name)->getName();
      auto upMBGoal = mbg.at(name);
      mbg.erase(name);
      mbg.insert(pair<string,MBGoal*>(newName,upMBGoal));

      printInfo(mbg.at(newName));
  }
    break;

  //update a specific robot
  case 2:
  {
      string name;
      string newName;
      cout<< "Which robot would you like to update"<< endl;
      cin>>name;

      updateRobot(rob.at(name));
      newName = rob.at(name)->getName();
      auto upRob = rob.at(name);
      rob.erase(name);
      rob.insert(pair<string,Robot*>(newName,upRob));
      

      

      printRoboInfo(rob.at(newName));


  }
    break;

  //find distance between mbgoals
  case 3:
  {
      string mb1;
      string mb2;
      cout<<"First mobile goal: ";
      cin>>mb1;
      cout<<endl;
      cout<<"Second mobile goal: ";
      cin>>mb2;
      cout<<endl;
      cout << "The distance is: "<<dist_btw_MBGs(mbg.at(mb1),mbg.at(mb2))<<endl;
  }
    break;
  //find distance between a robot and a mbgoal
  case 4:
  {
      string rob1;
      string mb;
      cout<<"Robot: ";
      cin>>rob1;
      cout<<endl;
      cout<<"Mobile goal: ";
      cin>>mb;
      cout<<endl;
      cout << "The distance is: "<<dist_Rob_MBG(rob.at(rob1),mbg.at(mb))<<endl;
  }
    break;

  case 5:

    break;

  case 0:
        
    break;



}

}


 for (auto pObj = MBGList.begin();
        pObj != MBGList.end(); ++pObj) {
      delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }

for (auto pObj = BotList.begin();
        pObj != BotList.end(); ++pObj) {
      delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }
   return 0;
}

