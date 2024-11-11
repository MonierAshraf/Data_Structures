// Author: Ahmed Khaled, 6 oct 24.
/***
 * Why OOP ? 
 * Encapsulation.
 * Abstraction. (Information Hiding) (Ploymorphism)
 * Inheritance. (code reuse)
 */

#include <iostream>
#include <string>
using namespace std;

class Room
{
    private:
        float length;
        float breadth;
        string name;
    public:
        Room(){     
        length = 6.9;
        breadth = 4.2;
        name = "bed room";}

        Room(float l){
        length = l;
        breadth = 7.2;
        name = "living room";}


        Room(float l, float b, string n){
        length = l;
        breadth = b;
        name = n;
        }
        void display_info(){
            cout<<"Room Type is "<<name<<" its lenght by breadth is " << length <<" x "<<breadth<<endl;
        }
    ~Room()
    {
        cout << "Item " << name << " destroyed!" << endl;
    }
    void set_length(float l){
        length = l;
    }
    float get_length(){
        return length;
    }
};

int main(){

    // 
    Room r1;
    Room r2(100.2);
    Room r3(10.5, 10.5, "study room");

    // r1.display_info();
    // r2.display_info();
    // r3.display_info();
    cout<< "get_length"<<r1.get_length()<<endl;

    r1.set_length(10.5);
    cout<< "get_length"<<r1.get_length()<<endl;

    return 0;
}
