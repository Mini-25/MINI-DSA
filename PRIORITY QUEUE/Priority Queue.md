  # Priority Queue Implementation Documentation

## Table of Contents
1. [Code Overview](#code-overview)
2. [Implementation Details](#implementation-details)
3. [Class Structure](#class-structure)
4. [Method Analysis](#method-analysis)
5. [Main Program Walkthrough](#main-program-walkthrough)
6. [Output Analysis](#output-analysis)
7. [Example Scenarios](#example-scenarios)
8. [Complexity Analysis](#complexity-analysis)

## 1. Code Overview

### Purpose
This implementation creates a priority queue data structure using a linked list, where elements are arranged based on their priority values. Higher priority elements are positioned at the front of the queue.

### Features
- Priority-based insertion
- Highest priority element removal
- Front element access
- Empty queue checking
- Queue display functionality
- Priority-based ordering (higher numbers = higher priority)

## 2. Implementation Details

### Node Structure
```cpp
struct Node {
    int data;
    int priority;
    Node* next;
    Node(int value, int prio) : data(value), priority(prio), next(nullptr) {}
};
```

#### Components:
- `data`: Stores integer value
- `priority`: Stores priority level
- `next`: Pointer to next node
- Constructor initializes node with value, priority, and null pointer

### Class Definition
```cpp
class PriorityQueue {
    private:
        Node* front;
    public:
        // Public interface methods
};
```

## 3. Class Structure

### Private Members
1. **Front Node Pointer**
   ```cpp
   Node* front;
   ```
   - Points to the highest priority element
   - Initialized to nullptr in constructor

### Public Interface
1. **Constructor**
   ```cpp
   PriorityQueue(): front(nullptr) {}
   ```

2. **Primary Operations**
   - `insert(int value, int priority)`
   - `pop()`
   - `top()`
   - `isEmpty()`
   - `display()`

## 4. Method Analysis

### Insert Method
```cpp
void insert(int value, int priority) {
    Node* newNode = new Node(value, priority);
    if (front == nullptr || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    } 
    else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
```

#### Algorithm Steps:
1. Create new node with value and priority
2. Handle empty queue or higher priority than front
3. Otherwise:
   - Traverse to find correct position
   - Insert maintaining priority order
4. Complexity: O(n)

### Pop Method
```cpp
void pop() {
    if (front == nullptr) {
        cout << "Priority Queue is empty." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
}
```

#### Process:
1. Check if queue is empty
2. Store front node
3. Update front pointer
4. Delete removed node
5. Complexity: O(1)

### Top Method
```cpp
int top() {
    if (front != nullptr)
        return front->data;
    cout << "Priority Queue is empty." << endl;
    return -1;
}
```

#### Features:
1. Returns highest priority element
2. Error handling for empty queue
3. Complexity: O(1)

### Display Method
```cpp
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
```

#### Implementation:
1. Empty queue check
2. Traverse and print all elements
3. Show priority levels
4. Complexity: O(n)

## 5. Main Program Walkthrough

```cpp
int main() {
    PriorityQueue pq;
    
    // Insertion operations
    pq.insert(10, 2);
    pq.insert(20, 3);
    pq.insert(15, 1);
    pq.insert(30, 5);
    pq.insert(25, 4);
    
    // Display operations
    cout << "Priority Queue after inserting elements: " << endl;
    pq.display();
    
    // Access and removal operations
    cout << "Element with highest priority: " << pq.top() << endl;
    pq.pop();
    cout << "Priority Queue after removing the highest priority element: " << endl;
    pq.display();
    
    return 0;
}
```

## 6. Output Analysis

Sample Output:
```
Priority Queue after inserting elements:
30 (Priority: 5) -> 25 (Priority: 4) -> 20 (Priority: 3) -> 10 (Priority: 2) -> 15 (Priority: 1) -> NULL
Element with highest priority: 30
Priority Queue after removing the highest priority element:
25 (Priority: 4) -> 20 (Priority: 3) -> 10 (Priority: 2) -> 15 (Priority: 1) -> NULL
```

## 7. Example Scenarios

### Scenario 1: Empty Queue
```cpp
PriorityQueue pq;
pq.pop();          // Output: Priority Queue is empty.
cout << pq.top();  // Output: Priority Queue is empty. -1
```

### Scenario 2: Same Priority
```cpp
PriorityQueue pq;
pq.insert(10, 2);
pq.insert(20, 2);  // Will be placed after first element with priority 2
```

### Scenario 3: Highest Priority Insert
```cpp
PriorityQueue pq;
pq.insert(10, 1);
pq.insert(20, 2);
pq.insert(30, 3);  // Will be placed at front
```

## 8. Complexity Analysis

### Time Complexity

| Operation | Average Case | Worst Case | Best Case |
|-----------|--------------|------------|-----------|
| Insert    | O(n)        | O(n)       | O(1)      |
| Pop       | O(1)        | O(1)       | O(1)      |
| Top       | O(1)        | O(1)       | O(1)      |
| isEmpty   | O(1)        | O(1)       | O(1)      |
| Display   | O(n)        | O(n)       | O(1)      |

### Space Complexity
- Overall: O(n) where n is number of elements
- Per operation:
  - Insert: O(1) for new node
  - Pop: O(1)
  - Other operations: O(1)

### Memory Usage
- Node size: sizeof(int) * 2 + sizeof(pointer)
- Total memory: Node size * number of elements
