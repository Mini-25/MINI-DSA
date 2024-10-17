#include <iostream>
using namespace std;

// Node class definition
struct Node {
    int data;      
    Node* next;    
    Node* prev;    
    Node(int value) : data(value), next(nullptr), prev(nullptr){}
};

// DoublyLinkedList class definition
class DoublyLinkedList {
private:
    Node* head; 
    Node* tail; 

public:
    // Constructor to initialize the head and tail to nullptr
    DoublyLinkedList() head(nullptr), tail(nullptr){}

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to delete the first node of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Function to delete the last node of the list
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Function to display the list forward
    void displayForward() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to display the list backward
    void displayBackward() {
        if (tail == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert nodes
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    // Display the list
    cout << "Doubly Linked List after insertions (forward): ";
    list.displayForward();
    cout << "Doubly Linked List after insertions (backward): ";
    list.displayBackward();

    // Delete nodes
    list.deleteFromBeginning();
    cout << "Doubly Linked List after deleting from the beginning: ";
    list.displayForward();

    list.deleteFromEnd();
    cout << "Doubly Linked List after deleting from the end: ";
    list.displayForward();

    return 0;
}
