
#include<conio.h>
#include <iostream>
#include <string>
#include "mbgoal.h"
#include <map>
#include <vector>
#include "Robot.h"
#include <sstream>
#include "float.h"
using namespace std;

//global stctures and variables
vector <MBGoal*> MBGList;
vector <Robot*> BotList;
map<string, MBGoal*> mbg;
map<string, Robot*> rob;




//creating map for neighbors to add to each MBS
map<string, MBGoal*> initMap (string line)
{

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

void findClosestMBG (Robot *current){
map<string, MBGoal*> :: iterator it = mbg.begin();

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



 cout<<"The current field is flat and has the dimensions of 100m by 100m"<< endl;

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
        // cout<<"inputed" <<endl;

        Neighbors = initMap(setMB);
         //cout<<"completed initmap"<<endl;


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

    for(int i=0;i<MBGList.size(); i++){
         printInfo(MBGList[i]);
         cout<<endl;
          findNearestMBG(MBGList[i]) ;  
          cout<<endl;
     }

        map<string, Robot*> :: iterator it = rob.begin();

        while(it!= rob.end()){
       
            printRoboInfo(it->second);
            cout<<endl;
  
            it++;
    }   




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

  case 1:
  {
      string name;
      string newName;
      cout<< "Which mobile goal would you like to update"<< endl;
      cin>>name;

      updateMBGoal(mbg.at(name));
      newName = mbg.at(name)->getName();
      mbg.insert(pair<string,MBGoal*>(newName,mbg.at(name)));
      mbg.erase(name);

     // name = mbg.at(name)->getName();

      printInfo(mbg.at(newName));

  }
    break;

  
  case 2:
  {
      string name;
      string newName;
      cout<< "Which robot would you like to update"<< endl;
      cin>>name;

      updateRobot(rob.at(name));
      newName = rob.at(name)->getName();
      rob.insert(pair<string,Robot*>(newName,rob.at(name)));
      rob.erase(name);

      

      printRoboInfo(rob.at(newName));


  }
    break;

  
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


 for (vector<MBGoal*>::iterator pObj = MBGList.begin();
        pObj != MBGList.end(); ++pObj) {
      delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }

for (vector<Robot*>::iterator pObj = BotList.begin();
        pObj != BotList.end(); ++pObj) {
      delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }
   return 0;
}

