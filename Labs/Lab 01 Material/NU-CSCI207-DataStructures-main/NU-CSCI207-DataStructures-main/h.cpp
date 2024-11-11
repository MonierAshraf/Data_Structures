#include <iostream>
#include<string>
using namespace std; 
class Car2{
private : 
int speed;
string model;
public :
Car2()
{
speed = 0;
model = "Unknown";
}
Car2(int spd, string mdl)
{
speed = spd;
model=mdl;
}

~Car2()
{}

void tes(int spd)
{
cout<<"Speed is : "<<spd<<endl;
}

};

int main()
{

Car2 c1;
Car2 c2(100,"BMW");

c2.tes(100);
return 0;
}