# Comprehensive Documentation: Improved DynamicArray, Queue, and Graph Implementation

## Table of Contents
1. [Introduction](#introduction)
2. [DynamicArray Class](#dynamicarray-class)
3. [Queue Class](#queue-class)
4. [Graph Class](#graph-class)
5. [Main Function](#main-function)
6. [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
7. [Best Practices and Design Choices](#best-practices-and-design-choices)
8. [Potential Further Improvements](#potential-further-improvements)
9. [Usage Examples](#usage-examples)
10. [Error Handling and Edge Cases](#error-handling-and-edge-cases)
11. [Conclusion](#conclusion)

## 1. Introduction

This documentation covers the improved implementation of three fundamental data structures: DynamicArray, Queue, and Graph. These improvements address various issues related to memory management, error handling, and overall robustness of the code.

## 2. DynamicArray Class

### Class Definition
```cpp
class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;
    void resize(int capacity);
public:
    DynamicArray();
    ~DynamicArray();
    void push_back(int value);
    int& operator[](int index);
    int getSize() const;
};
```

### Detailed Method Descriptions

#### Constructor
```cpp
DynamicArray(): arr(new int[1]), size(0), capacity(1) {}
```
- Initializes the array with a capacity of 1
- Sets size to 0 and capacity to 1

#### Destructor
```cpp
~DynamicArray() {
    delete[] arr;
}
```
- Frees the dynamically allocated memory

#### resize (private method)
```cpp
void resize(int capacity) {
    int* new_arr = new int[capacity*2];
    for(int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = capacity*2;
}
```
- Creates a new array with double the capacity
- Copies elements from the old array to the new array
- Deletes the old array and updates the pointer
- Updates the capacity

#### push_back
```cpp
void push_back(int value) {
    if(size == capacity) {
        resize(capacity);
    }
    arr[size++] = value;
}
```
- Resizes the array if it's at capacity
- Adds the new value to the end of the array
- Increments the size

#### operator[]
```cpp
int& operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return arr[index];
}
```
- Provides access to elements by index
- Throws an exception if the index is out of bounds

#### getSize
```cpp
int getSize() const {
    return size;
}
```
- Returns the current number of elements in the array
---

## 3. Queue Class

### Class Definition
```cpp
class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d): data(d), next(nullptr) {}
    };
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    void dequeue();
    int getFront();
    bool isEmpty();
};
```

### Detailed Method Descriptions

#### Constructor
```cpp
Queue(): front(nullptr), rear(nullptr) {}
```
- Initializes an empty queue with null front and rear pointers

#### Destructor
```cpp
~Queue() {
    while(!isEmpty()) {
        dequeue();
    }
}
```
- Deallocates all nodes in the queue

#### enqueue
```cpp
void enqueue(int value) {
    Node* temp = new Node(value);
    if(rear == nullptr) {
        front = rear = temp;
    }
    rear->next = temp;
    rear = temp;
}
```
- Adds a new node to the rear of the queue
- Updates front and rear pointers as necessary

#### dequeue
```cpp
void dequeue() {
    if (isEmpty()) {
        throw runtime_error("Cannot dequeue from an empty queue");
    }
    Node* temp = front;
    front = front->next;
    if(front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}
```
- Removes the front node from the queue
- Throws an exception if the queue is empty
- Updates front and rear pointers as necessary

#### getFront
```cpp
int getFront() {
    if(isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return front->data;
}
```
- Returns the data of the front node
- Throws an exception if the queue is empty

#### isEmpty
```cpp
bool isEmpty() {
    return front == nullptr;
}
```
- Checks if the queue is empty

---

## 4. Graph Class

### Class Definition
```cpp
class Graph {
private:
    int V;
    DynamicArray* adj;
public:
    Graph(int vertices);
    ~Graph();
    void addEdge_Undirected(int v, int w);
    bool hasEdge(int v, int w) const;
    void printGraph();
};
```

### Detailed Method Descriptions

#### Constructor
```cpp
Graph(int vertices): V(vertices) {
    adj = new DynamicArray[V];
}
```
- Initializes the graph with the specified number of vertices
- Creates an array of DynamicArrays to represent the adjacency list

#### Destructor
```cpp
~Graph() {
    delete[] adj;
}
```
- Frees the dynamically allocated array of DynamicArrays

#### addEdge_Undirected
```cpp
void addEdge_Undirected(int v, int w) {
    if (v < 0 || v >= V || w < 0 || w >= V) {
        throw std::out_of_range("Vertex index out of bounds");
    }
    adj[v].push_back(w);
    adj[w].push_back(v);
}
```
- Adds an undirected edge between vertices v and w
- Throws an exception if either vertex is out of bounds

#### hasEdge
```cpp
bool hasEdge(int v, int w) const {
    if (v < 0 || v >= V || w < 0 || w >= V) {
        throw std::out_of_range("Vertex index out of bounds");
    }
    for (int i = 0; i < adj[v].getSize(); ++i) {
        if (adj[v][i] == w) return true;
    }
    return false;
}
```
- Checks if an edge exists between vertices v and w
- Throws an exception if either vertex is out of bounds

#### printGraph
```cpp
void printGraph() {
    for (int v = 0; v < V; v++) {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int i = 0; i < adj[v].getSize(); i++) {
            cout << adj[v][i] << " ";
        }
        cout << endl;
    }
}
```
- Prints the adjacency list representation of the graph

---

## 5. Main Function

The main function demonstrates the usage of the Graph class:
- Creates a graph with 5 vertices
- Adds undirected edges between vertices
- Prints the graph representation

## 6. Time and Space Complexity Analysis

### DynamicArray
- push_back: Amortized O(1)
- operator[]: O(1)
- getSize: O(1)
- Space Complexity: O(n)

### Queue
- enqueue: O(1)
- dequeue: O(1)
- getFront: O(1)
- isEmpty: O(1)
- Space Complexity: O(n)

### Graph
- addEdge_Undirected: O(1)
- hasEdge: O(degree(v))
- printGraph: O(V + E)
- Space Complexity: O(V + E)

## 7. Best Practices and Design Choices

- Use of exception handling for error cases
- Const-correctness in method declarations
- Encapsulation of internal data structures
- Clear separation of concerns between classes

## 8. Potential Further Improvements

- Implement copy constructor and assignment operator for DynamicArray
- Use templates to make the classes more generic
- Implement iterators for the DynamicArray and Graph classes
- Add more graph algorithms (e.g., DFS, BFS)

## 9. Usage Examples

```cpp
// Creating and using a DynamicArray
DynamicArray arr;
arr.push_back(1);
arr.push_back(2);
cout << arr[0] << " " << arr[1] << endl;

// Creating and using a Queue
Queue q;
q.enqueue(10);
q.enqueue(20);
cout << q.getFront() << endl;
q.dequeue();

// Creating and using a Graph
Graph g(5);
g.addEdge_Undirected(0, 1);
g.addEdge_Undirected(0, 2);
g.printGraph();
```

## 10. Error Handling and Edge Cases

- DynamicArray throws out_of_range exception for invalid indices
- Queue throws runtime_error for operations on an empty queue
- Graph throws out_of_range exception for invalid vertex indices

## 11. Conclusion
This implementation showcases the power and flexibility of custom data structures. The DynamicArray provides efficient dynamic storage, the Queue offers fast FIFO operations, and the Graph represents complex relationships between entities.
