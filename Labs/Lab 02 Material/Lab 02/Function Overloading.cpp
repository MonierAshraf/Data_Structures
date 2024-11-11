#include <iostream>
using namespace std;

class Example {
public:
    // Function with one parameter
    void display(int x) {
        cout << "Integer: " << x << endl;
    }

    // Overloaded function with a different parameter type
    void display(double x) {
        cout << "Double: " << x << endl;
    }

    // Overloaded function with a different number of parameters
    void display(int x, double y) {
        cout << "Integer: " << x << ", Double: " << y << endl;
    }
};

int main() {
    Example ex;
    ex.display(5);           // Calls display(int)
    ex.display(5.5);         // Calls display(double)
    ex.display(5, 10.5);     // Calls display(int, double)
    return 0;
}
