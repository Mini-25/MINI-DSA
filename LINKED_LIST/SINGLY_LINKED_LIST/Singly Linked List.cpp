#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
};
class LinkedList{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}
        void insert(int val){
            Node* newNode = new Node;
            newNode->val = val;
            newNode->next = head;
            head = newNode;
        }
        void remove(){
            if (!head) {
                cout << "Error: List is empty, cannot remove." << endl;
                return;
            }
            if (!head->next) {
                // Only one node in the list
                delete head;
                head = nullptr;
            } else {
                // More than one node in the list
                Node* temp = head;
                while (temp->next->next) {
                    temp = temp->next;
                }
                // Now temp is the second-to-last node
                delete temp->next;
                temp->next = nullptr;
            }
        }
        void print(){
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void delAll(){
        Node* temp = head;
        while(temp){
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
    ~LinkedList(){
        delAll();
    }
};
int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();
    list.remove();
    list.print();
}