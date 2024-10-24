#include<iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
    
    Node(int value, int prio) : data(value), priority(prio), next(nullptr) {}
};

class PriorityQueue {
    private:
        Node* front;

    public:
        PriorityQueue() : front(nullptr) {}

        // Insert based on priority (higher priority at the front)
        void insert(int value, int priority) {
            Node* newNode = new Node(value, priority);
            // If queue is empty or new node has higher priority than the front
            if (front == nullptr || priority > front->priority) {
                newNode->next = front;
                front = newNode;
            } 
            else {
                Node* temp = front;
                // Traverse to find correct position
                while (temp->next != nullptr && temp->next->priority >= priority) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        // Remove element with the highest priority (front of the queue)
        void pop() {
            if (front == nullptr) {
                cout << "Priority Queue is empty." << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        // Get the element with the highest priority
        int top() {
            if (front != nullptr)
                return front->data;
            cout << "Priority Queue is empty." << endl;
            return -1; // Indicating queue is empty
        }

        // Check if the queue is empty
        bool isEmpty() {
            return front == nullptr;
        }

        // Display the queue
        void display() {
            if (front == nullptr) {
                cout << "Priority Queue is empty." << endl;
                return;
            }
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " (Priority: " << temp->priority << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    PriorityQueue pq;

    // Insert elements with priority
    pq.insert(10, 2);
    pq.insert(20, 3);
    pq.insert(15, 1);
    pq.insert(30, 5);
    pq.insert(25, 4);

    cout << "Priority Queue after inserting elements: " << endl;
    pq.display();

    cout << "Element with highest priority: " << pq.top() << endl;

    pq.pop();
    cout << "Priority Queue after removing the highest priority element: " << endl;
    pq.display();

    pq.pop();
    cout << "Priority Queue after removing the highest priority element again: " << endl;
    pq.display();

    return 0;
}
