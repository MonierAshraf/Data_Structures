#include <iostream>
using namespace std;

template <class T>  // Template the Stack class
struct StackNode {
    T item;
    StackNode *next;
};

template <class T>
class Stack {
    StackNode<T> *top;
public:
    Stack() {
        top = NULL;
    }
    bool isEmpty() {
        return top == NULL;
    }

    bool isEmpty2() {
    if (top == NULL)
    return true;
    else
    return false;
    }
    void push(T newItem) {
        StackNode<T> *newPtr = new StackNode<T>;  // Allocate as StackNode<T>
        if (newPtr == NULL)
            cout << "Stack push cannot allocate memory";
        else {
            newPtr->item = newItem;
            newPtr->next = top;
            top = newPtr;
        }
    }
void push2 (T item) {
StackNode<T> *newNode = new StackNode<T>;
newNode->item = item;
if (top == NULL)   { // If the stack is empty
newNode->next = NULL;
top = newNode;
}
else{
newNode->next = top;
top = newNode;
}}
 void pop() {
        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            StackNode<T> *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }



    void pop(T &stackTop) {  // Pass stackTop by reference
        if (isEmpty())
            cout << "Stack empty on pop";
        else {
            stackTop = top->item;
            StackNode<T> *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    T Peek() {
        if (isEmpty()) {
            cout << "stack empty on getTop";
            return T();  // Return a default value of T if stack is empty
        } else {
            return top->item;  // Corrected return statement
        }
    }
    void display() {
        StackNode<T> *curPtr = top;
        cout << "\nItems in the stack : ";
        cout << "[ ";
        while (curPtr != NULL) {
            cout << curPtr->item << " ";
            curPtr = curPtr->next;
        }
        cout << "]\n";
    }
};

int main() {
    Stack<int> s;
        int topValue;  // Variable to store the popped top item

    s.push(10);
    s.push(20);
    s.push(0);
        s.push(10);
    s.push(20);
        s.display();

    s.pop();
    s.display();
    cout << "Top of the stack : " << s.Peek() << endl;

    return 0;
}
