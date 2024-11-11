#include <iostream>
using namespace std;

class Super {
private:
    int privateVar = 1;  // Private variable, not accessible in the derived class

protected:
    int protectedVar = 2;  // Protected variable, accessible in the derived class

public:
    int publicVar = 3;  // Public variable, accessible from anywhere

    // Public method to display variables from Super class
    void Print() {
        cout << "I am Super Class" << endl;
        cout << "PrivateVar: " << privateVar << endl;  // Accessible here in the base class
        cout << "ProtectedVar: " << protectedVar << endl;  // Accessible here in the base class
        cout << "PublicVar: " << publicVar << endl;  // Accessible here in the base class
    }
};

class Child : public Super {
public:
    // Override the Print method
    void Print() {
        cout << "I am Child Class" << endl;
        // Access to Super class's private variable is not allowed:
        // cout << privateVar << endl;  // ERROR: privateVar is not accessible in derived class
        // Access to Super class's protected variable is allowed:
        cout << "ProtectedVar (from Super): " << protectedVar << endl;
        // Access to Super class's public variable is allowed:
        cout << "PublicVar (from Super): " << publicVar << endl;
    }
};
int main() {
    Child obj;
    // Call overridden Print method
    obj.Print();
    // Direct access to public member
    cout << "Direct access to publicVar: " << obj.publicVar << endl;  // Allowed
    // Direct access to protected and private members from outside is not allowed:
    // cout << obj.protectedVar << endl;  // ERROR: protectedVar is not accessible from outside
    // cout << obj.privateVar << endl;    // ERROR: privateVar is not accessible from outside
    return 0;
}
