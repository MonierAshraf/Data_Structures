#include <iostream>
#include <string>
using namespace std;
class person{
private:
    int id;
    string name;
    public:
    person (int id , string name){
this->id =id;
this->name = name;

    }

template <class t>
void print_v(t v){

    cout<<v<<endl;
}
int get_id(){
    return id;
}
string getName(){
    return name;
}
};

class emp:public person{
private :
float salary;
public:

emp (int id2 ,string name2 ,float salary2):person(id2,name2){
salary= salary2;
}

void display(){
    cout<<"ID: ";
    print_v(get_id());
    cout<<"Name: ";
    print_v(getName());
    cout<<"Salary: ";
    print_v(salary);
}
};


int main(){
emp  m1(1,"Monier ", 20000.0);
m1.display();    
    return 0;





}