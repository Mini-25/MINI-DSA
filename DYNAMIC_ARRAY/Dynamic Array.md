# Dynamic Array Implementation Documentation

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
This implementation creates a dynamic array data structure that automatically resizes itself when needed. It provides basic operations for inserting, removing, and displaying elements, along with an added search functionality.

### Features
- Dynamic memory allocation
- Automatic resizing
- Element insertion
- Element removal
- Array printing
- Element searching (newly added)

## 2. Implementation Details

### Class Structure
```cpp
class DynamicArray {
    private:
        int* array;
        int capacity;
        int size;
        void resize();
    public:
        DynamicArray();
        ~DynamicArray();
        void insert(int element);
        void remove();
        void print();
        int search(int element); // New method
};
```

#### Components:
- `array`: Pointer to dynamic integer array
- `capacity`: Maximum current array capacity
- `size`: Current number of elements
- `resize()`: Private helper method for array expansion

## 3. Class Structure

### Private Members
1. **Array Pointer**
   ```cpp
   int* array;
   ```
   - Points to dynamically allocated array
   - Managed through constructor/destructor

2. **Array Properties**
   ```cpp
   int capacity;  // Maximum array size
   int size;      // Current number of elements
   ```

3. **Resize Helper**
   ```cpp
   void resize() {
       int* newArray = new int[capacity * 2];
       for (int i = 0; i < size; i++) {
           newArray[i] = array[i];
       }
       delete[] array;
       array = newArray;
       capacity = capacity * 2;
   }
   ```

### Public Interface
1. **Constructor & Destructor**
   ```cpp
   DynamicArray(): capacity(1), size(0) {
       array = new int[capacity];
   }
   
   ~DynamicArray() {
       delete[] array;
   }
   ```

2. **Primary Operations**
   - `insert(int element)`
   - `remove()`
   - `print()`
   - `search(int element)`

## 4. Method Analysis

### Insert Method
```cpp
void insert(int element) {
    if (size == capacity) {
        resize();
    }
    array[size] = element;
    size++;
}
```

#### Algorithm Steps:
1. Check if array is full
2. Resize if necessary
3. Add element at current size index
4. Increment size
5. Complexity: O(1) amortized

### Remove Method
```cpp
void remove() {
    if (size > 0) {
        size--;
    } else {
        cout << "Error: List is empty, cannot remove." << endl;
    }
}
```

#### Process:
1. Check if array is not empty
2. Decrement size if possible
3. Display error if empty
4. Complexity: O(1)

### Print Method
```cpp
void print() {
    cout << "List: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
```

### Search Method 
```cpp
int search(int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;  // Element not found
}
```

#### Features:
1. Linear search implementation
2. Returns index if found
3. Returns -1 if not found
4. Complexity: O(n)

## 5. Main Program Walkthrough

```cpp
int main() {
    DynamicArray myList;
    
    // Insert operations
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.print();
    
    // Remove operation
    myList.remove();
    myList.print();
    
    // Additional insertions
    myList.insert(40);
    myList.insert(50);
    myList.print();
    
    // Search operations
    int index = myList.search(40);
    if (index != -1) {
        cout << "Element 40 found at index: " << index << endl;
    }
    
    return 0;
}
```

## 6. Output Analysis

Sample Output:
```
List: 10 20 30
List: 10 20
List: 10 20 40 50
Element 40 found at index: 2
```

## 7. Example Scenarios

### Scenario 1: Empty List
```cpp
DynamicArray list;
list.print();        // Output: List:
list.remove();       // Output: Error: List is empty, cannot remove.
```

### Scenario 2: Resizing
```cpp
DynamicArray list;
list.insert(1);      // capacity: 1
list.insert(2);      // triggers resize, capacity: 2
list.insert(3);      // triggers resize, capacity: 4
```

### Scenario 3: Search Operations
```cpp
DynamicArray list;
list.insert(10);
list.insert(20);
cout << list.search(20);  // Output: 1
cout << list.search(30);  // Output: -1
```

## 8. Complexity Analysis

### Time Complexity

| Operation | Average Case | Worst Case | Best Case |
|-----------|--------------|------------|-----------|
| Insert    | O(1)*       | O(n)       | O(1)      |
| Remove    | O(1)        | O(1)       | O(1)      |
| Search    | O(n)        | O(n)       | O(1)      |
| Print     | O(n)        | O(n)       | O(n)      |
| Resize    | O(n)        | O(n)       | O(n)      |

*Amortized time complexity

### Space Complexity
- Base: O(n) where n is the number of elements
- During resize: O(2n) temporarily

### Memory Usage
- Initial capacity: 1 element
- Growth factor: 2x
- Memory overhead: O(1) for size and capacity tracking
