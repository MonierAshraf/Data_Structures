#include <iostream>
#include <string>
using namespace std;
class person {
private:
int id;
string name;
public:
person(int id, string name) {
    this->id = id;
    this-> name= name;
}

int getId() {
    return id;
}
string getName() {
    return name;
}
template<class t>
void printValue(t value) {
    cout << value << endl;
}

};

class emp: public person {
private:
float salary;
public:
emp (int id , string name , float salary) :person(id,name){
    this->salary = salary;

}

void display() {
    cout << "ID: ";
     printValue(getId());
    cout << "Name: "; 
    printValue( getName() );
    cout << "Salary: " ;
   printValue( salary );


}


};
int main () {
emp employee(2, "Ahmed", 2000.0f);
employee.display();
return 0;







}