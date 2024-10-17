#include<iostream>
using namespace std;

class Stack {
    private:
        int* arr;
        int top, capacity;
    public:
        Stack(int size = 5): top(-1), capacity(size) {
            arr = new int[capacity];
        }

        bool push(int value) {
            if (isFull()) {
                cout << "Stack overflow! Cannot push " << value << endl;
                return false; 
            }
            arr[++top] = value;
            return true; 
        }

        bool pop() {
            if (isEmpty()) {
                cout << "Stack underflow! Cannot pop" << endl;
                return false; 
            }
            top--;
            return true;
        }

        // Peek function to return top element without removing it
        int peek() const {
            if (isEmpty()) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return arr[top];
        }

        // Check if the stack is empty
        bool isEmpty() const {
            return top < 0;
        }

        // Check if the stack is full
        bool isFull() const {
            return top == capacity - 1;
        }

        // Get the current size of the stack
        int size() const {
            return top + 1;
        }

        // Display the stack contents
        void display() const {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Destructor to free allocated memory
        ~Stack() {
            delete[] arr;
        }
};

int main() {
    Stack s(5); // Create a stack of capacity 5

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // Stack overflow should occur here

    cout << "Current stack: ";
    s.display();

    // Peek at the top element
    cout << "Top element: " << s.peek() << endl;

    // Pop an element
    s.pop();
    cout << "After popping, current stack: ";
    s.display();

    return 0;
}
