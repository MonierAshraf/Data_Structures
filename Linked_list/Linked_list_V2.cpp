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
class linkedlist {
public:
    Node<T>* head;

    linkedlist() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->Data << " ";
            temp = temp->next;
        }
    }

    int count() {
        Node<T>* temp = head;
        int counter = 0;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(T key) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->Data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void insert_Start(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;
        newNode->next = head;
        head = newNode;
    }

    void insert_before(T item, T newvalue) {
        Node<T>* newnode = new Node<T>();
        newnode->Data = newvalue;

        if (head == NULL) {
            cout << "List is empty. Cannot insert before." << endl;
            return;
        }

        if (head->Data == item) {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != NULL && temp->next->Data != item) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Item not found" << endl;
        } else {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void append(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void Delete(T value) {
        Node<T>* temp = head;
        Node<T>* prev = NULL;

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL && temp->Data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Item not found" << endl;
        } else if (prev == NULL) {
            head = temp->next;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void Delete_all() {
        Node<T>* temp = head;
        while (temp != NULL) {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
        cout << "List is empty" << endl;
    }
};

int main() {
    linkedlist<int> lst;

    lst.isEmpty();
    lst.insert_Start(10);
    lst.insert_Start(20);
    lst.insert_Start(30);
    lst.display();
    cout << endl;

    cout << "count = " << lst.count();
    cout << endl;

    if (lst.search(20)) {
        cout << "found 20 " << endl;
    } else {
        cout << "not found 20" << endl;
    }

    lst.insert_before(20, 25);
    lst.display();
    cout << endl;

    lst.append(40);
    lst.display();
    cout << endl;

    lst.Delete(20);
    lst.display();
    cout << endl;

    lst.Delete_all();
    lst.display();

    return 0;
}
