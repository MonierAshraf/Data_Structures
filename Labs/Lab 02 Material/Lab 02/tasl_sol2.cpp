#include <iostream>
using namespace std;

// Base class Animal
class Animal {
protected:
    string color = "default color";  // Protected member with default value

public:
    // Public template method to print any value
    template <class  T>
    void print_value(T value) {
        cout << value << endl;
    }

    // Getter for color (protected member)
    string get_color() {
        return color;
    }

    // Method to display the current color using the template print method
    void display_color() {
        cout << "Color: ";
        print_value(color);  // Calling template method to print color
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    // Method to update the dog's color
    void update_dog_color() {
        color = "Brown";  // Accessing protected member from parent class
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Method to update the cat's color
    void update_cat_color() {
        color = "White";  // Accessing protected member from parent class
    }
};

// Main function
int main() {
    // Creating objects of Dog and Cat
    Dog dog;
    Cat cat;

    // Updating colors
    dog.update_dog_color();
    cat.update_cat_color();

    // Displaying updated colors using the template method for printing
    cout << "Dog's ";
    dog.display_color();
    cout << "Cat's ";
    cat.display_color();

    return 0;
}
