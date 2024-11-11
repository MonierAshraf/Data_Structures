#include <iostream>
using namespace std;

class Base {
public:
    // Base class function
    void display() {
        cout << "Display from Base Class" << endl;
    }
};

class Derived : public Base {
public:
    // Derived class overriding the base class function
    void display() {
        cout << "Display from Derived Class" << endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    // Call the display function from both base and derived class objects
    baseObj.display();        // Calls Base class's display()
    derivedObj.display();     // Calls Derived class's display()

    return 0;
}
