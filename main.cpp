
#include <iostream>
#include <string>
using namespace std;


class MBGoal {

    public:

    MBGoal(string, int, int);

    int posX ,posY;
    string name;


};

MBGoal:: MBGoal (string label,int a,int b){
name =  label;
   posX = a;
   posY = b;

}

int main(){


    MBGoal mb1 ("mb1", 20 ,40);
    cout << "Current position of "<< mb1.name<< " is "  << mb1.posX << ", " << mb1.posY << endl;
    return 0;
}


