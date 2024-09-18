//Doubly linked list
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x): data(x), next(nullptr), prev(nullptr){}
};
class DoublyLinkedList{
    Node* head;
    public:
    DoublyLinkedList():head(nullptr){}
    void insertAtHead(int x){
        Node* temp = new Node(x);
        if(head == nullptr){
            head = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    void insertAtTail(int x){
        Node* temp = new Node(x);
        if(head == nullptr){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr->next!= nullptr){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    void insertAtPos(int x, int pos){
        Node* temp = new Node(x);
        if(head == nullptr){
            head = temp;
            return;
        }
        Node* curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;
    }
    void deleteAtHead(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void deleteAtTail(){
        if(head == nullptr){
            return;
        }
        Node* curr = head;
        while(curr->next!= nullptr){
            curr = curr->next;
        }
        curr->prev->next = nullptr;
        delete curr;
    }
    void deleteAtPos(int pos){
        if(head == nullptr){
            return;
        }
        Node* curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    void display(){
        Node* curr = head;
        while(curr!= nullptr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    void deleteAll(){
        Node* curr = head;
        while(curr!= nullptr){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }
    ~DoublyLinkedList(){
        deleteAll();
    }
};
int main(){
    DoublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtHead(4);
    dll.insertAtHead(5);
    dll.display();
    dll.insertAtTail(6);
    dll.insertAtTail(7);
    dll.insertAtTail(8);
    dll.insertAtTail(9);
    dll.display();
    dll.insertAtPos(10, 3);
    dll.display();
    dll.deleteAtHead();
    dll.display();
    dll.deleteAtTail();
    dll.display();
    dll.deleteAll(  );
    dll.display();
}