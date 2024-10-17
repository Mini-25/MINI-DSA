#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next;     
    Node(int value) : data(value), next(nullptr) {}
};

// CircularLinkedList class definition
class CircularLinkedList {
private:
    Node* head;  

public:
    CircularLinkedList() : head(nullptr) {}

    
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to delete the first node of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* oldHead = head;
            head = head->next;
            temp->next = head;
            delete oldHead;
        }
    }

    // Function to delete the last node of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    // Function to display the list
    void displayList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "head" << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Insert nodes
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    // Display the list
    cout << "Circular Linked List after insertions: ";
    list.displayList();

    // Delete nodes
    list.deleteFromBeginning();
    cout << "Circular Linked List after deleting from the beginning: ";
    list.displayList();

    list.deleteFromEnd();
    cout << "Circular Linked List after deleting from the end: ";
    list.displayList();

    return 0;
}
