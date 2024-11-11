#include <iostream>
using namespace std;
#include <string>
class Car3 {
private :
    int speed;
    string model;   
    public:
    Car3 (){
        speed = 0;
        model = "Unknown";
        cout << "Car object created def "<< endl;
    }
    Car3 (int spd, string mdl){
        speed = spd;
        model = mdl;
        cout << "Car object created par "<< endl;

    }
    void setSpeed(int spd){
        speed = spd;
    }
    void setModel(string mdl){
        model = mdl;
    }
    int getSpeed(){
        return speed;
    }
string getModel(){
    return model;}
void calspeed (int miles)
{
cout << "It will take " << (double)miles / speed << " hours to travel " << miles << " miles." << endl;

}

};

int main (){
Car3 car1;
Car3 car2(100, "Toyota");
cout << "Car2 speed is " << car1.getSpeed() << endl;
car1.setSpeed(60);
cout << "Car2 speed is " << car1.getSpeed() << endl;
car1.calspeed(100);



return 0;

}
