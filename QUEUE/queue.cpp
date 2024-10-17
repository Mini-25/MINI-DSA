#include<iostream>
using namespace std;

class Queue {
    private:
        int* arr;        
        int front;       
        int rear;        
        int capacity;    
        int count;       

    public:
        // Constructor to initialize queue
        Queue(int size = 5): front(0), rear(-1), capacity(size), count(0) {
            arr = new int[capacity]; 
        }

        // Function to add an element to the queue (enqueue operation)
        bool enqueue(int value) {
            if (isFull()) {
                cout << "Queue overflow! Cannot enqueue " << value << endl;
                return false;
            }
            // Circular queue logic for rear
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            count++;
            return true;
        }

        // Function to remove an element from the queue (dequeue operation)
        bool dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow! Cannot dequeue" << endl;
                return false;
            }
            // Circular queue logic for front
            front = (front + 1) % capacity;
            count--;
            return true;
        }

        // Function to get the front element of the queue without removing it
        int peek() const {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }

        // Function to check if the queue is empty
        bool isEmpty() const {
            return count == 0;
        }

        // Function to check if the queue is full
        bool isFull() const {
            return count == capacity;
        }

        // Function to get the current size of the queue
        int size() const {
            return count;
        }

        // Function to display all elements of the queue
        void display() const {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            int i = front;
            for (int k = 0; k < count; k++) {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }

        // Destructor to free allocated memory
        ~Queue() {
            delete[] arr;
        }
};

int main() {
    Queue q(5); 

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  

    // Display the current queue
    cout << "Current queue: ";
    q.display();

    // Peek at the front element
    cout << "Front element: " << q.peek() << endl;

    // Dequeue an element
    q.dequeue();
    cout << "After dequeuing, current queue: ";
    q.display();

    return 0;
}
