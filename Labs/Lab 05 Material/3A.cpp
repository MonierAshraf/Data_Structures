#include <iostream>
#include <string>
using namespace std;


template<class T>
class stack_node{
public:
T Data; 
stack_node *next;
};

template<class T>
class Stack2{
public:
stack_node <T> * head;
Stack2(){head =NULL;}
bool isEmpty(){
if(head == NULL){
return true;
}
else{    
return false;}}
void Display(){
stack_node<T> *temp = head;
while (temp != NULL){
cout<<temp->Data;
temp = temp->next;
}
}
void push(T item){
stack_node<T> *newNode = new stack_node<T>; 

newNode->Data=item;
if (isEmpty()){
head = newNode;
newNode->next = NULL;
}
else{
newNode->next = head;
head = newNode;

}


}
void pop(){
stack_node<T> *temp = head; 

if (isEmpty()){
cout<<"Stack is empty";
}
else{
head= head->next;

delete temp;
cout<<"Item is popped" <<temp->next <<endl;

}
cout<<"Item is " <<temp->next <<endl;
}

T pop2(){

stack_node<T> *temp = head; 

if (isEmpty()){
cout<<"Stack is empty";
}
else{
head= head->next;
T item = temp->Data;
temp->next = NULL;
delete temp;
return item;

}


}


T peek(){
if (isEmpty()){
cout<<"Stack is empty";
}
else{   
return head->Data;
}

}
};

int main(){ 
Stack2<int> s;
s.push(10);
s.push(20);
s.push(40);
s.Display();
cout<<endl;
s.pop();
s.Display();
cout<<endl;



}