#include<conio.h>
#include <iostream>
#include <string>
#include "mbgoal.h"
#include <map>
#include <vector>
using namespace std;



int main(){

 vector <MBGoal> MBGList;
 map<string, MBGoal> mbg;
   int numMB;
 //  clrscr();
     cout<<"How many mobile Goals will there be?"<< endl;
     cin >> numMB;
 // MBG = new MBGoal[numMB];


     for (int i=0; i < numMB; i++){
         //MBGoal a ("null", 0,0)
         string name;
         int x;
         int y ;
         int neighbors;
         cout<<"Name of mobile goal #"<<(i+1)<<" : ";
         cin>>name;
         cout<<endl;
         cout << "Starting x position of "<< name << " : ";
         cin>> x;
         cout<<endl;
         cout << "Starting y position of "<< name<< " : ";
         cin>> y;
         cout<<endl;
         cout << "Number of neighbors for  "<<name << " : ";
         cin>> neighbors;
         cout<<endl;
         MBGoal *MBG = (MBGoal *)make_MBG(x,y,name,neighbors);
         MBGList.push_back(*MBG);
         mbg.insert(pair<string,MBGoal>(name,*MBG));
//
     }

     for(int i=0;i<MBGList.size(); i++){
         printInfo(&MBGList[i]);
       
     }






   return 0;
}


