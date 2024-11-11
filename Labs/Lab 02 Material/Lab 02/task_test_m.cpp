#include <iostream>
#include <string>
using namespace std;



class animal{
protected:
    string color = "default color";

public:
void display_color() {
    cout << "Color: " ;

    print_value(color);
}

template <typename t>
void print_value(t value) {
    cout << value << endl;
}



};


class dog:public animal{public:
void update_dog_color() {
    color = "Brown";
}

};
class cat:public animal{
    public:
void update_cat_color() {
    color = "White";
}


};


int main() {
    dog dog;
    cat cat;
    dog.update_dog_color();
    cat.update_cat_color();
    cout << "Dog's ";
    dog.display_color();
    cout << "Cat's ";
    cat.display_color();
    return 0;
}

