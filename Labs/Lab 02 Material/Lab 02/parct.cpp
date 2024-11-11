#include <iostream>
#include <string>
using namespace std;

// Template class Person
template <typename T>
class Person {
private:
    T ID;          // Private ID number of any type
    string name;   // Private name
public:
    // Parameterized constructor
    Person(T ID, string name) : ID(ID), name(name) {

        
    }

    // Public getter for ID and name
    T getID() {
        return ID;
    }

    string getName() {
        return name;
    }
};

// Class Emp inheriting from Person
class Emp : public Person<int> {  // Inherits with integer ID
private:
    float salary;  // Private salary
public:
    // Parameterized constructor that reuses the parent constructor
    Emp(int ID, string name, float salary) : Person(ID, name), salary(salary) {}

    // Public getter for salary
    float getSalary() {
        return salary;
    }

    // Method to display employee's information
    void display() {
        cout << "ID: " << getID() << ", Name: " << getName() << ", Salary: " << salary << endl;
    }
};

int main() {
    // Create an object of Emp
    Emp employee(123, "John Doe", 50000.0);

    // Display the employee's information
    employee.display();

    return 0;
}
