# Comprehensive Queue Documentation

## Table of Contents
1. [Introduction](#introduction)
2. [Data Structure Overview](#data-structure-overview)
3. [Detailed Implementation Explanation](#detailed-implementation-explanation)
4. [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
5. [Code Implementation](#code-implementation)
6. [Step-by-Step Code Breakdown](#step-by-step-code-breakdown)
7. [Example Run with Visualization](#example-run-with-visualization)
8. [Common Pitfalls and Tips](#common-pitfalls-and-tips)
9. [Variants of Queue](#variants-of-queue)
10. [Real-world Applications](#real-world-applications)
11. [Practice Problems](#practice-problems)
12. [Conclusion](#conclusion)

## 1. Introduction

A Queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. It is an abstract data type with a bounded (predefined) capacity. It allows adding elements to the rear and removing elements from the front. The first element added to the queue will be the first one to be removed.

### Key Concepts:
- Elements are added to the rear of the queue (enqueue operation)
- Elements are removed from the front of the queue (dequeue operation)
- Only the front element is accessible for removal at any given time
- Follows the First-In-First-Out (FIFO) principle

## 2. Data Structure Overview

The Queue implementation consists of:

1. **Array**: To store the elements of the queue.
2. **Front**: An integer to keep track of the index of the front element.
3. **Rear**: An integer to keep track of the index of the rear element.
4. **Capacity**: The maximum number of elements the queue can hold.
5. **Count**: The current number of elements in the queue.

Key operations include:
- Enqueue: Add an element to the rear of the queue
- Dequeue: Remove the front element from the queue
- Peek: View the front element without removing it
- isEmpty: Check if the queue is empty
- isFull: Check if the queue is full

## 3. Detailed Implementation Explanation

### Queue Class
```cpp
class Queue {
private:
    int* arr;
    int front, rear, capacity, count;
public:
    Queue(int size = 5);
    bool enqueue(int value);
    bool dequeue();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void display() const;
    ~Queue();
};
```
- `arr`: Dynamic array to store queue elements
- `front`: Index of the front element
- `rear`: Index of the rear element
- `capacity`: Maximum number of elements the queue can hold
- `count`: Current number of elements in the queue
- Constructor initializes the queue with a given capacity (default 5)
- Destructor frees the dynamically allocated memory

### Key Operations

1. **Enqueue**:
   - Check if the queue is full
   - If not full, add the new element at the rear and update rear and count
   - Return true if successful, false if queue overflow

2. **Dequeue**:
   - Check if the queue is empty
   - If not empty, update front and decrease count
   - Return true if successful, false if queue underflow

3. **Peek**:
   - Check if the queue is empty
   - If not empty, return the element at the front
   - Return -1 if queue is empty (assuming -1 is not a valid queue element)

4. **isEmpty**:
   - Return true if count is 0, false otherwise

5. **isFull**:
   - Return true if count equals capacity, false otherwise

6. **size**:
   - Return the current count of elements

7. **display**:
   - Iterate through the array from front to rear, printing each element

## 4. Time and Space Complexity Analysis

### Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
- isEmpty: O(1)
- isFull: O(1)
- size: O(1)
- display: O(n), where n is the number of elements in the queue

### Space Complexity:
- O(n), where n is the capacity of the queue

## 5. Code Implementation

```cpp
#include <iostream>
using namespace std;

class Queue {
    private:
        int* arr;
        int front, rear, capacity, count;
    public:
        Queue(int size = 5): front(0), rear(-1), capacity(size), count(0) {
            arr = new int[capacity];
        }

        bool enqueue(int value) {
            if (isFull()) {
                cout << "Queue overflow! Cannot enqueue " << value << endl;
                return false;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            count++;
            return true;
        }

        bool dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow! Cannot dequeue" << endl;
                return false;
            }
            front = (front + 1) % capacity;
            count--;
            return true;
        }

        int peek() const {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }

        bool isEmpty() const {
            return count == 0;
        }

        bool isFull() const {
            return count == capacity;
        }

        int size() const {
            return count;
        }

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

        ~Queue() {
            delete[] arr;
        }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "Current queue: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "After dequeuing, current queue: ";
    q.display();

    return 0;
}
```

## 6. Step-by-Step Code Breakdown

### Constructor
```cpp
Queue(int size = 5): front(0), rear(-1), capacity(size), count(0) {
    arr = new int[capacity];
}
```
- Initializes `front` to 0, `rear` to -1 (empty queue)
- Sets `capacity` to the given size (default 5)
- Initializes `count` to 0 (empty queue)
- Dynamically allocates an array of size `capacity`

### Enqueue
```cpp
bool enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow! Cannot enqueue " << value << endl;
        return false;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
    return true;
}
```
- Checks if queue is full
- If not full, updates `rear` using circular logic, adds the new value, and increments `count`
- Returns true on success, false on overflow

### Dequeue
```cpp
bool dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow! Cannot dequeue" << endl;
        return false;
    }
    front = (front + 1) % capacity;
    count--;
    return true;
}
```
- Checks if queue is empty
- If not empty, updates `front` using circular logic and decrements `count`
- Returns true on success, false on underflow

### Peek
```cpp
int peek() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[front];
}
```
- Checks if queue is empty
- If not empty, returns the front element without removing it

### Other Methods
- `isEmpty()`: Returns true if `count` is 0
- `isFull()`: Returns true if `count` equals `capacity`
- `size()`: Returns `count`
- `display()`: Iterates through the array from front to rear, printing each element

### Destructor
```cpp
~Queue() {
    delete[] arr;
}
```
- Frees the dynamically allocated memory for the array

## 7. Example Run with Visualization

Let's visualize the queue operations in the main function:

1. Initial state: [ ]
2. After enqueuing 10, 20, 30, 40, 50: [10, 20, 30, 40, 50]
3. Trying to enqueue 60: Queue overflow! [10, 20, 30, 40, 50]
4. Peek operation: Returns 10
5. After dequeuing: [20, 30, 40, 50]

## 8. Common Pitfalls and Tips

1. **Queue Overflow**: Always check for full queue before enqueuing.
2. **Queue Underflow**: Always check for empty queue before dequeuing or peeking.
3. **Memory Leaks**: Ensure proper deallocation of dynamic memory.
4. **Circular Implementation**: Be careful with the circular logic to avoid off-by-one errors.
5. **Type Safety**: Consider using templates for type-flexible implementation.

## 9. Variants of Queue

1. **Circular Queue**: Optimizes space usage (implemented in this example).
2. **Double-ended Queue (Deque)**: Allows insertion and deletion at both ends.
3. **Priority Queue**: Elements are dequeued based on priority rather than order of insertion.
4. **Linked List Queue**: Implements queue using a linked list instead of an array.

## 10. Real-world Applications

1. **Task Scheduling**: Managing processes in operating systems.
2. **Breadth-First Search**: Used in graph algorithms for traversal.
3. **Buffering**: Managing data buffers in various applications (e.g., video streaming).
4. **Printer Queue**: Managing print jobs in order of arrival.

## 11. Practice Problems

1. Implement a queue using two stacks.
2. Design a circular queue with dynamic resizing.
3. Implement a queue that supports getMin() operation in O(1) time.
4. Create a program to reverse the first K elements of a queue.

## 12. Conclusion

Queues are fundamental data structures in computer science with numerous applications in algorithm design and system programming. Their FIFO principle makes them ideal for managing ordered data and processes. The circular array-based implementation provided here offers constant-time operations for enqueue and dequeue, making it efficient for most use cases. Understanding queue operations and their implementations is crucial for solving complex problems involving ordered processing and for optimizing code performance in various scenarios.
