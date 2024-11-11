#include <iostream>
#include <string>
using namespace std;
class Node 
{
    public:

int data;
Node* next;
};


class linkedlist{
public:
Node* head;
linkedlist(){
    head = NULL;

}

bool isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
void display(){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        
        }
    };

int count(){

    int counter=0;
    Node* temp = head;
    while(temp!= NULL){
        counter++;
        temp = temp->next;
        }
        return counter;

    };

bool isfound(int key){
    Node* temp = head;

    while(temp!= NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
        }
        return false;
    };

void insertbefore(int item , int newvalue){
    Node* newnode = new Node();
    newnode->data = newvalue;
    Node* temp = head;

 if (isfound(item)){
while (temp != NULL && temp->next->data!= item)
{    temp = temp->next;
}
newnode->next = temp->next; 
temp->next = newnode;



    }

else{
    cout<<"Item not found to add"<<endl;}

}
void instertfirst(int newvalue){
       Node *newnode = new Node();
        newnode->data = newvalue  ;
    if (isEmpty()){
        newnode-> next = NULL;
        head = newnode;
    }
    else{
     newnode-> next = head;
        head = newnode;
    }
}

void append(int newvalue){
Node *newnode = new Node();
newnode->data = newvalue;
newnode->next = NULL;

if(isEmpty()){
instertfirst(newvalue);
}
else{
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}}

void Delete(int key){
    Node* temp = head;
    Node* prev = NULL;

    if(isEmpty()){
        cout<<"List is empty"<<endl;
    }
    else{
        while(temp != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Item not found"<<endl;
        }
        else if(prev == NULL){
            head = head->next;
            delete temp;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }
    }

}

};




int main() {
    linkedlist lst;

    if (lst.isEmpty()){
        cout<<"List is empty"<<endl;
    }
    else{
        
        cout<<"List count "<< lst.count()<<endl;}
        
        lst.instertfirst(10);
                lst.instertfirst(20);

        lst.display();
        cout<<endl;

        lst.append(200);
        lst.Delete(10);
        cout<<"List count "<< lst.count()<<endl;
                lst.display();

    return 0;
};
