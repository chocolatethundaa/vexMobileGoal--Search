#include<conio.h>
#include <iostream>
#include <string>
using namespace std;


class MBGoal {
    int posX, posY;
    string name;
    bool isScored;
    public:

    //MBGoal(string, int, int);

    void setXY (int x, int y){
        posX = x;
        posY = y;
    }
    int getPosX () { return posX;}
    int getPosY () { return posY;}
    void changeName(string x){
        name = x;
    }
    string getName(){

        return name;
    }





};
///constructor
/*MBGoal:: MBGoal (string label,int a,int b){
name =  label;
   posX = a;
   posY = b;

}
*/
int main(){

 MBGoal *MBG;

   int numMB;
 //  clrscr();
     cout<<"How many mobile Goals will there be?"<< endl;
     cin >> numMB;
  MBG = new MBGoal[numMB];


     for (int i=0; i < numMB; i++){
         //MBGoal a ("null", 0,0)
         string name;
         int positionX;
         int positionY;
         cout<<"Name of mobile goal #"<<(i+1)<<" : ";
         cin>>name;
         MBG[i].changeName(name);
         cout << "Starting x position of "<< MBG[i].getName()<< " : ";
         cin>> positionX;
         cout << "Starting y position of "<< MBG[i].getName()<< " : ";
         cin>> positionY;

         MBG[i].setXY(positionX,positionY);

     }


   


    /*MBGoal mb1 ("mb1", 20 ,40);

    ptr = &mb1;

    cout << "Current position of "<< ptr->getName()<< " is "  << ptr->getPosX()<< ", " << ptr->getPosX()<< endl;
   
   */ return 0;
}


