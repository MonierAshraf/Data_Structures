#include <iostream>
#include <string>
using namespace std;

template <class T> 
class stackNode{
    public:

T Data;
stackNode <T> *next;

};

template <class T>
class Stack {
stackNode <T> *head;
public:

Stack(){
head = NULL;
}
bool isempty(){
if (head == NULL)
return true;
else    
return false;
}
void display(){
if (isempty())
cout << "Stack is empty" << endl;
else{
stackNode <T> *temp = head;
while (temp != NULL){
cout << temp->Data << " ";
temp = temp->next;
}


}}

void push(T item){
stackNode <T> *newnode = new stackNode<T>;
newnode->Data=item;


if (isempty()){
head = newnode;
newnode->next = NULL;
}
else{

newnode->next = head;
head = newnode;
}

}
void pop(){
stackNode <T> *temp = head; 

if (isempty())  {

    cout << "Stack is empty" << endl;
}
else{
head = head->next;
temp->next=NULL;
delete temp;
}}
T peek(){
if (isempty()){
cout << "Stack is empty" << endl;
}
else{
    return head->Data;
}
}

};
int main() {
Stack<int> s;
s.push(10);
s.push(20);
s.push(0);
s.display();
cout << endl;

s.pop();
s.display();
cout << endl;
cout << "Top of the stack : " << s.peek() << endl;

return 0;


};