#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
    Node* head;
    Node* tail;

    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr){}

        void insert(int val) {
            Node* newNode = new Node(val);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void remove() {
            if (head == nullptr) {
                cout << "Error: List is empty, cannot remove." << endl;
                return;
            }

            if (head->next == nullptr) {
                // Only one node in the list
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else if (head == tail) {
                // Last node in the list
                delete tail;
                head->prev = nullptr;
                tail = head;
            }
            else {
                // More than one node in the list
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
        void print(){
            Node* temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;   
        }
};

int main(){
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();
    list.remove();
    list.print();
    return 0;
}