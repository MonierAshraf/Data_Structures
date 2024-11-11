#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node {
public:
T data;
 Node* next;
};


template <class T>
class linkedlist{
public:
Node<T> *head;
linkedlist(){
head = NULL;
}
bool isempty(){ 
if (head == NULL){
return true;
}
else{
    return false;
}

}
void display(){
if (isempty()){
    cout<<"List is empty in display"<<endl;
}
else{
    Node<T> *temp = head;
    while (temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
}
int count(){ 

        Node<T> *temp = head;
        int counter = 0;
        while (temp!= NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    
}
bool search(T key){
Node<T>* temp = head;
while (temp!= NULL){
    if (temp->data==key){
    return true;

}       
   
temp = temp->next;
}
return false;


}

void insert_start(T value){
Node<T> *newNode = new Node<T>();
    newNode->data = value;
    if (head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

}
void Delete(T value){
Node <T> *temp = head;
Node <T> *prev = NULL;


if (isempty()){
    cout<<"List is empty in delete"<<endl;
}
else{
    while (temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        cout<<"Item not found"<<endl;
    }
    else if (prev == NULL){
        head = temp->next;
        delete temp;
    }
    else{
        prev->next = temp->next;
        delete temp;
    }}




}


};

int main(){
linkedlist <int> l;
l.isempty();    
l.display();
l.count();
l.insert_start(5);
l.insert_start(6);
cout<<"search"<<l.search(5);
cout<<endl;

l.insert_start(7);
l.display();

cout<<endl;
l.Delete(5);

l.display();
return 0;

};













