#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node {
public:
T Data;
Node* next;
};
template <class T>

class linkedlist{
public:
Node<T>* head;

linkedlist(){
head = NULL;
}

bool isEmpty(){
if(head == NULL){
return true;
}
else{
return false;
}}

void display(){
Node<T>* temp = head;

while (temp!= NULL){
cout<<temp->Data<<" ";
temp= temp->next;


}
}

int count(){
Node<T>* temp = head;
int counter = 0;
while(temp!= NULL){
counter++;
temp = temp->next;
}
return counter;

}

bool sreach(T key){
Node<T>* temp = head;
while (temp!= NULL){
    if (temp->Data==key){
    return true;

}       
else{   
temp = temp->next;
return false;
}

}
}

void instert_Start(T value){
Node<T>* newNode = new Node<T>();
newNode->Data = value;

if (head == NULL){
   newNode->next = NULL;
    head = newNode; 
}
else{

newNode->next = head;
head = newNode;

}}
void instert_before(T item,T newvalue){
Node<T>* newnode = new Node<T>();
newnode->Data = newvalue;
Node<T>* temp = head;

if (sreach(item)){
while(temp != NULL && temp->next->Data != item){
    temp = temp->next;

}

newnode->next = temp->next;
temp->next = newnode;
}
else{
    cout<<"Item not found"<<endl;
}

}

void append(T value){
Node<T>* newNode = new Node<T>();
newNode->Data = value;
newNode->next = NULL;
if (isEmpty()){
    head = newNode;
}
else{
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

}


void Delete(T value){
Node<T>* temp = head;
Node<T>* prev = NULL;
if (isEmpty()){
    cout<<"List is empty"<<endl;
}
else{
    while (temp != NULL && temp->Data !=value){
        prev = temp;
        temp = temp->next;
    }
    
    if (temp ==NULL){
     cout<<"Item not found"<<endl;   

    }
    else if (prev==NULL)
    {
        head= temp->next;
        delete temp;
    }
    else {
prev->next= temp->next;
delete temp;
    }
}




}

void Delete_all(){
Node<T>* temp = head;
Node<T>* prev = NULL;
if (isEmpty()){
    cout<<"List is empty"<<endl;
}
else{
    while (temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    head = NULL;
    cout<<"List is empty"<<endl;}


}


};



int main() {
    linkedlist <int > lst;


    if (lst.isEmpty()){
        cout<<"List is empty"<<endl;
    }
    else{
        
        cout<<"List count "<< lst.count()<<endl;}
        
        lst.instert_Start(10);
                lst.instert_Start(20);

        lst.display();
        cout<<endl;

        lst.append(200);
        lst.display();
        lst.Delete(10);
        cout<<"List count "<< lst.count()<<endl;
                lst.display();
                   cout<<endl;
          lst.Delete_all();      


    return 0;
};
