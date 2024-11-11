#include <iostream>
using namespace std;
#include <string>
class Car2{
    private : 
    int speed;
    string model;
    public:
    Car2(){
        speed = 0;
        model = "Unknown";
        cout << "Car object created def "<< endl;
    }
    Car2(int spd, string mdl){
        speed = spd;
        model = mdl;
       cout << "Car object created par "<< endl;

    }
void setSpeed(int spd){
    speed = spd;}

int getSpeed(){
    return speed;}

void calspeed (int miles){
    if(speed > 0){
        double time = (double)miles / speed;
        cout << "It will take " << time << " hours to travel " << miles << " miles." << endl;
    }else{
        cout << "Speed must be greater than 0!" << endl;
    }}
void calspeed (double miles){
    if(speed > 0){
        double time = (double)miles / speed;
        cout << " double = " << time << " hours to travel " << miles << " miles." << endl;
    }else{
        cout << "Speed must be greater than 0!" << endl;
    }}

~Car2(){
    cout << "Car object destroyed<< endl";
}
};
int main(){
    Car2 car1;
    
    Car2 car2(100, "Toyota");
cout << "Car2 speed is " << car1.getSpeed() << endl;
    car1.setSpeed(60);
cout << "Car2 speed is " << car1.getSpeed() << endl;

   car1.calspeed(100);
   car1.calspeed(100.5);
    return 0;


}
