# Comprehensive Stack Documentation

## Table of Contents
1. [Introduction](#introduction)
2. [Data Structure Overview](#data-structure-overview)
3. [Detailed Implementation Explanation](#detailed-implementation-explanation)
4. [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
5. [Code Implementation](#code-implementation)
6. [Step-by-Step Code Breakdown](#step-by-step-code-breakdown)
7. [Example Run with Visualization](#example-run-with-visualization)
8. [Common Pitfalls and Tips](#common-pitfalls-and-tips)
9. [Variants of Stack](#variants-of-stack)
10. [Real-world Applications](#real-world-applications)
11. [Practice Problems](#practice-problems)
12. [Conclusion](#conclusion)

## 1. Introduction

A Stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It is an abstract data type with a bounded (predefined) capacity. It allows adding and removing elements in a particular order. Every time an element is added, it goes on the top of the stack, and the only element that can be removed is the element that was added last.

### Key Concepts:
- Elements are added to the top of the stack
- Elements are removed from the top of the stack
- Only the top element is accessible at any given time
- Follows the Last-In-First-Out (LIFO) principle

## 2. Data Structure Overview

The Stack implementation consists of:

1. **Array**: To store the elements of the stack.
2. **Top**: An integer to keep track of the index of the topmost element.
3. **Capacity**: The maximum number of elements the stack can hold.

Key operations include:
- Push: Add an element to the top of the stack
- Pop: Remove the top element from the stack
- Peek: View the top element without removing it
- isEmpty: Check if the stack is empty
- isFull: Check if the stack is full

## 3. Detailed Implementation Explanation

### Stack Class
```cpp
class Stack {
private:
    int* arr;
    int top, capacity;
public:
    Stack(int size = 5);
    bool push(int value);
    bool pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void display() const;
    ~Stack();
};
```
- `arr`: Dynamic array to store stack elements
- `top`: Index of the topmost element (-1 if stack is empty)
- `capacity`: Maximum number of elements the stack can hold
- Constructor initializes the stack with a given capacity (default 5)
- Destructor frees the dynamically allocated memory

### Key Operations

1. **Push**:
   - Check if the stack is full
   - If not full, increment top and add the new element
   - Return true if successful, false if stack overflow

2. **Pop**:
   - Check if the stack is empty
   - If not empty, decrement top
   - Return true if successful, false if stack underflow

3. **Peek**:
   - Check if the stack is empty
   - If not empty, return the element at the top
   - Return -1 if stack is empty (assuming -1 is not a valid stack element)

4. **isEmpty**:
   - Return true if top is less than 0, false otherwise

5. **isFull**:
   - Return true if top is equal to capacity - 1, false otherwise

6. **size**:
   - Return top + 1 (since top is 0-indexed)

7. **display**:
   - Iterate through the array from 0 to top, printing each element

## 4. Time and Space Complexity Analysis

### Time Complexity:
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- isEmpty: O(1)
- isFull: O(1)
- size: O(1)
- display: O(n), where n is the number of elements in the stack

### Space Complexity:
- O(n), where n is the capacity of the stack

## 5. Code Implementation

```cpp
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

    int peek() const {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top < 0;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    int size() const {
        return top + 1;
    }

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

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "Current stack: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After popping, current stack: ";
    s.display();

    return 0;
}
```

## 6. Step-by-Step Code Breakdown

### Constructor
```cpp
Stack(int size = 5): top(-1), capacity(size) {
    arr = new int[capacity];
}
```
- Initializes `top` to -1 (empty stack)
- Sets `capacity` to the given size (default 5)
- Dynamically allocates an array of size `capacity`

### Push
```cpp
bool push(int value) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push " << value << endl;
        return false;
    }
    arr[++top] = value;
    return true;
}
```
- Checks if stack is full
- If not full, increments `top` and adds the new value
- Returns true on success, false on overflow

### Pop
```cpp
bool pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Cannot pop" << endl;
        return false;
    }
    top--;
    return true;
}
```
- Checks if stack is empty
- If not empty, decrements `top`
- Returns true on success, false on underflow

### Peek
```cpp
int peek() const {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return arr[top];
}
```
- Checks if stack is empty
- If not empty, returns the top element without removing it

### Other Methods
- `isEmpty()`: Returns true if `top` is less than 0
- `isFull()`: Returns true if `top` equals `capacity - 1`
- `size()`: Returns `top + 1`
- `display()`: Iterates through the array, printing each element

### Destructor
```cpp
~Stack() {
    delete[] arr;
}
```
- Frees the dynamically allocated memory for the array

## 7. Example Run with Visualization

Let's visualize the stack operations in the main function:

1. Initial state: [ ]
2. After pushing 10, 20, 30, 40, 50: [10, 20, 30, 40, 50]
3. Trying to push 60: Stack overflow! [10, 20, 30, 40, 50]
4. Peek operation: Returns 50
5. After popping: [10, 20, 30, 40]

## 8. Common Pitfalls and Tips

1. **Stack Overflow**: Always check for full stack before pushing.
2. **Stack Underflow**: Always check for empty stack before popping or peeking.
3. **Memory Leaks**: Ensure proper deallocation of dynamic memory.
4. **Boundary Conditions**: Be careful with off-by-one errors in array indexing.
5. **Type Safety**: Consider using templates for type-flexible implementation.

## 9. Variants of Stack

1. **Dynamic Stack**: Automatically resizes when full.
2. **Linked List Stack**: Implements stack using a linked list instead of an array.
3. **Circular Stack**: Uses a circular array to optimize space.
4. **Thread-Safe Stack**: Implements concurrency control for multi-threaded applications.

## 10. Real-world Applications

1. **Function Call Stack**: Manages function calls and local variables in program execution.
2. **Expression Evaluation**: Used in calculators and compilers for evaluating expressions.
3. **Undo Mechanism**: Implements undo functionality in text editors and graphic software.
4. **Backtracking Algorithms**: Used in maze solving, puzzle solving, and game AI.

## 11. Practice Problems

1. Implement a function to reverse a string using a stack.
2. Create a program to check if parentheses in an expression are balanced using a stack.
3. Implement a stack that supports getMin() operation in O(1) time.
4. Design a queue using two stacks.

## 12. Conclusion

Stacks are fundamental data structures in computer science with a wide range of applications. Their simplicity and efficiency make them indispensable in many algorithms and system designs. Understanding stack operations and their implementations is crucial for solving complex problems and optimizing code performance.

The array-based implementation provided here offers constant-time operations for push, pop, and peek, making it efficient for most use cases. However, it's important to consider the fixed-size limitation and explore other implementations like dynamic or linked-list-based stacks for scenarios requiring more flexibility.
