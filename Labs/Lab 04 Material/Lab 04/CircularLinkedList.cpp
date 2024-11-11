#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T Data;
    Node* next;
    Node* prev; // Previous pointer for backward traversal
};

template <class T>
class CircularLinkedList {
public:
    Node<T>* head;

    CircularLinkedList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    // Display the list in a circular manner, stopping when we loop back to the head
    void display() {
        if (isEmpty()) return;

        Node<T>* temp = head;
        do {
            cout << temp->Data << " ";
            temp = temp->next;
        } while (temp != head); // Stop when we circle back to the head
        cout << endl;
    }

    // Display the list in reverse order in a circular manner
    void displayReverse() {
        if (isEmpty()) return;

        // Move to the last node
        Node<T>* temp = head->prev;
        do {
            cout << temp->Data << " ";
            temp = temp->prev;
        } while (temp != head->prev); // Stop when we loop back to the last node
        cout << endl;
    }

    int count() {
        if (isEmpty()) return 0;

        Node<T>* temp = head;
        int counter = 0;
        do {
            counter++;
            temp = temp->next;
        } while (temp != head);
        return counter;
    }

    bool search(T key) {
        if (isEmpty()) return false;

        Node<T>* temp = head;
        do {
            if (temp->Data == key) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Insert a node at the beginning
    void insert_Start(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;

        if (isEmpty()) {
            // When the list is empty, newNode points to itself
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node<T>* last = head->prev;

            // Insert the new node before head
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode; // Update head to new node
        }
    }

    // Insert a new node before a specific item
    void insert_before(T item, T newvalue) {
        if (isEmpty()) {
            cout << "List is empty. Cannot insert before." << endl;
            return;
        }

        Node<T>* temp = head;
        do {
            if (temp->Data == item) {
                Node<T>* newnode = new Node<T>();
                newnode->Data = newvalue;

                // Insert new node before temp
                newnode->next = temp;
                newnode->prev = temp->prev;
                temp->prev->next = newnode;
                temp->prev = newnode;

                if (temp == head) {
                    head = newnode; // Update head if inserted at the start
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Item not found" << endl;
    }

    // Append a node at the end
    void append(T value) {
        Node<T>* newNode = new Node<T>();
        newNode->Data = value;

        if (isEmpty()) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node<T>* last = head->prev;

            // Insert new node after last node
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
        }
    }

    // Delete a node with the specified value
    void Delete(T value) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* temp = head;

        do {
            if (temp->Data == value) {
                if (temp->next == temp) { // Single node case
                    delete temp;
                    head = NULL;
                    return;
                }

                // Adjust pointers of neighboring nodes
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next; // Update head if we delete the first node
                }

                delete temp; // Free memory of the deleted node
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Item not found" << endl;
    }

    // Delete all nodes in the circular list
    void Delete_all() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        do {
            Node<T>* nextNode = temp->next;
            delete temp; // Free each node's memory
            temp = nextNode;
        } while (temp != head);

        head = NULL; // Set head to NULL after deletion
        cout << "List is empty" << endl;
    }
};

int main() {
    CircularLinkedList<int> lst;

    lst.insert_Start(10);
    lst.insert_Start(20);
    lst.insert_Start(30);
    lst.display();

    cout << "Count = " << lst.count() << endl;

    if (lst.search(20)) {
        cout << "Found 20" << endl;
    } else {
        cout << "Not found 20" << endl;
    }

    lst.insert_before(20, 99);
    lst.display();

    lst.append(40);
    lst.display();

    lst.Delete(99);
    lst.display();

    lst.displayReverse();

    lst.Delete_all();
    lst.display();

    return 0;
}
