#include<conio.h>
#include <iostream>
#include <string>
#include "mbgoal.h"
#include <map>
#include <vector>
using namespace std;



int main(){


 cout<<"The current field is flat and has the dimensions of 100m by 100m"<< endl;
 
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
       /*  cout << "Number of neighbors for  "<<name << " : ";
         cin>> neighbors;
         cout<<endl;
         MBGoal *MBG = (MBGoal *)make_MBG(x,y,name,neighbors);
         MBGList.push_back(*MBG);
         mbg.insert(pair<string,MBGoal>(name,*MBG));
//*/
        MBGList.push_back(MBGoal(name,x,y));
        mbg.insert(pair<string,MBGoal>(name,MBGList[i]));

     }

     for(int i=0;i<MBGList.size(); i++){
         printInfo(&MBGList[i]);
       
     }

 


string answer1;
string answer2;
cout<< "What would you like to find the distance between? "<< endl;

cin>>answer1;
cin>>answer2;


cout << "The distance is: "<<dist_btw_MBGs(&mbg.at(answer1),&mbg.at(answer2))<<endl;

/*
cin>>answer;
while (answer !="quit"){


    if 





    }

*
    printInfo(&mbg.at(answer));
    cout<< "What mobile goal info do you need? "<< endl;
    
    cin>>answer;

}


*/


   return 0;
}


