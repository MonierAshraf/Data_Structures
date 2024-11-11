#include <iostream>
#include <string>
using namespace std;

// Class Person
class Person {
private:
    int id;          // Private member
    string name;     // Private member

public:
    // Parameterized constructor for Person
    Person(int id, string name) {
       this -> id = id;
       this ->name = name;
       cout << "Person constructor called" << endl;
    }

    // Public template method to print any value
    template <class T>
    void printValue(T value) {
        cout << value << endl;
    }

    // Getter for ID (public access)
    int getId() {
        return id;
    }

    // Getter for Name (public access)
    string getName() {
        return name;
    }
};

// Class Emp inheriting from Person

class Emp : public Person {
private:
    float salary;  // Private member

public:
    // Parameterized constructor for Emp, reusing the parent's constructor
    Emp(int id, string name, float salary) : Person(id, name) {
        this->salary = salary;
    }

    // Public method to display employee's details using template method from Person
    void display() {
        cout << "ID: ";
        printValue(getId());       // Using the getter for ID and template method
        cout << "Name: ";
        printValue(getName());     // Using the getter for Name and template method
        cout << "Salary: ";
        printValue(salary);        // Using the template method directly to print salary
    }
};

int main() {
    // Creating an Emp object with id, name, and salary
    Emp employee(2, "Ahmed", 2000.0f);

    // Display employee information
    employee.display();

    return 0;
}
