#include<conio.h>
#include <iostream>
#include <string>
#include "mbgoal.h"
#include <map>
#include <vector>
//#include <windows.h>
#include "robot.h"
#include <graphics.h>
#include <sstream>
//#include <winbgim.h>
using namespace std;

//global stctures and variables
vector <MBGoal*> MBGList;
map<string, MBGoal*> mbg;




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






int main(){

 cout<<"The current field is flat and has the dimensions of 100m by 100m"<< endl;

   int numMB;
     cout<<"How many mobile Goals will there be?"<< endl;
     cin >> numMB;

//setup mbgfield
     for (int i=0; i < numMB; i++){
         string name;
         int x;
         int y ;
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
         cout<<"inputed" <<endl;

        Neighbors = initMap(setMB);
         cout<<"completed initmap"<<endl;


        mbg.at(currentMB)->setNeighbor(currentMB,mbg.at(currentMB), Neighbors);

        cout<<"completed setneighbors"<<endl;
        cout<< "Finished?" <<endl;
        cin>>finished;
    }


    for(int i=0;i<MBGList.size(); i++){
         printInfo(MBGList[i]);
          findNearestMBG(MBGList[i]) ;  
     }



string answer1;
string answer2;
string done;

while(done!= "Done"){
cout<< "What would you like to find the distance between? "<< endl;

cin>>answer1;
cin>>answer2;


cout << "The distance is: "<<dist_btw_MBGs(mbg.at(answer1),mbg.at(answer2))<<endl;

cout << "Are you done?"<< endl;
cin>>done;
}


 for (vector<MBGoal*>::iterator pObj = MBGList.begin();
        pObj != MBGList.end(); ++pObj) {
      delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }
   return 0;
}
