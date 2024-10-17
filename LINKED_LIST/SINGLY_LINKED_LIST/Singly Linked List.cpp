#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;    
    Node(int value): data(value), next(nullptr){}
};

// LinkedList class definition
class LinkedList {
private:
    Node* head; 

public:
    // Constructor to initialize the head to nullptr
    LinkedList() : head(nullptr){}

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); 
        newNode->next = head;            
        head = newNode;                
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {          
            head = newNode;             
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { 
                temp = temp->next;
            }
            temp->next = newNode;        
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
        delete temp;        
    }

    // Function to delete the last node of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;            
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) { 
                temp = temp->next;
            }
            delete temp->next;     
            temp->next = nullptr;    
        }
    }

    // Function to display the list
    void displayList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> "; 
            temp = temp->next;            
        }
        cout << "nullptr" << endl;       
    }
};

int main() {
    LinkedList list;  // Create an empty linked list

    // Insert nodes
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    // Display the list
    cout << "Linked List after insertions: ";
    list.displayList();

    // Delete nodes
    list.deleteFromBeginning();
    cout << "Linked List after deleting from the beginning: ";
    list.displayList();

    list.deleteFromEnd();
    cout << "Linked List after deleting from the end: ";
    list.displayList();

    return 0;
}
