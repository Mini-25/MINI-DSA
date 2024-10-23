# Binary Tree Implementation Documentation

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
This implementation creates a binary tree data structure with random node placement and various traversal methods. The tree supports basic operations like insertion and different types of tree traversals.

### Features
- Random node insertion
- In-order traversal
- Pre-order traversal
- Post-order traversal
- Level-order traversal
- Tree height calculation

## 2. Implementation Details

### Node Structure
```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}
};
```

#### Components:
- `data`: Stores integer value
- `left`: Pointer to left child node
- `right`: Pointer to right child node
- Constructor initializes a node with data and null pointers

### Class Definition
```cpp
class binaryTree {
    private:
        Node* root;
        // Private helper methods
    public:
        // Public interface methods
};
```

## 3. Class Structure

### Private Members
1. **Root Node Pointer**
   ```cpp
   Node* root;
   ```
   - Points to the top of the tree
   - Initialized to nullptr in constructor

2. **Helper Methods**
   - `inorder(Node* node)`
   - `preorder(Node* node)`
   - `postorder(Node* node)`
   - `height(Node* node)`
   - `levelOrder(Node* node)`
   - `printCurrentLevel(Node* node, int level)`

### Public Interface
1. **Constructor**
   ```cpp
   binaryTree(): root(nullptr){}
   ```

2. **Primary Operations**
   - `insert(int value)`
   - `inorderTraversal()`
   - `preorderTraversal()`
   - `postorderTraversal()`
   - `levelOrderTraversal()`
   - `getHeight()`

## 4. Method Analysis

### Insertion Method
```cpp
void insert(int value) {
    Node* newNode = new Node(value);
    if(root == nullptr)
        root = newNode;
    else {
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if(rand() % 2)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->left == nullptr)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
}
```

#### Algorithm Steps:
1. Create new node
2. If tree is empty, set as root
3. Otherwise:
   - Navigate randomly left or right
   - Track parent node
   - Insert at first available position
4. Complexity: O(h), where h is tree height

### Traversal Methods

#### 1. In-order Traversal
```cpp
void inorder(Node* node) {
    if(node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}
```

Process:
1. Traverse left subtree
2. Process current node
3. Traverse right subtree
4. Result: Ascending order for BST

#### 2. Pre-order Traversal
```cpp
void preorder(Node* node) {
    if(node != nullptr) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}
```

Use Cases:
- Creating copy of tree
- Getting prefix expression
- Tree serialization

#### 3. Post-order Traversal
```cpp
void postorder(Node* node) {
    if(node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}
```

Applications:
- Delete operations
- Calculate directory size
- Evaluate expressions

### Height Calculation
```cpp
int height(Node* node) {
    if(node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}
```

Process:
1. Base case: empty node returns 0
2. Recursively calculate:
   - Left subtree height
   - Right subtree height
3. Return max height + 1

### Level Order Traversal
```cpp
void levelOrder(Node* node) {
    int h = height(node);
    for(int i = 1; i <= h; i++)
        printCurrentLevel(node, i);
}

void printCurrentLevel(Node* node, int level) {
    if(node == nullptr)
        return;
    if(level == 1)
        cout << node->data << " ";
    else if(level > 1) {
        printCurrentLevel(node->left, level-1);
        printCurrentLevel(node->right, level-1);
    }
}
```

Implementation Details:
1. Calculate tree height
2. For each level:
   - Print nodes at current level
   - Recursively process next level

## 5. Main Program Walkthrough

```cpp
int main() {
    binaryTree tree;
    
    // Tree construction
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    
    // Traversal demonstrations
    cout << "In-order Traversal: ";
    tree.inorderTraversal();
    
    cout << "Pre-order Traversal: ";
    tree.preorderTraversal();
    
    cout << "Post-order Traversal: ";
    tree.postorderTraversal();
    
    cout << "Level-order Traversal: ";
    tree.levelOrderTraversal();
    
    cout << "Height of Tree: " << tree.getHeight() << endl;
    
    return 0;
}
```

## 6. Output Analysis

Sample Output:
```
In-order Traversal: 4 2 5 1 6 3 7
Pre-order Traversal: 1 2 4 5 3 6 7
Post-order Traversal: 4 5 2 6 7 3 1
Level-order Traversal: 1 2 3 4 5 6 7
Height of Tree: 3
```

Possible Tree Structure:
```
       1
      / \
     2   3
    / \ / \
   4  5 6  7
```

## 7. Example Scenarios

### Scenario 1: Empty Tree
```cpp
binaryTree tree;
tree.inorderTraversal(); // Output: empty line
cout << tree.getHeight(); // Output: 0
```

### Scenario 2: Single Node
```cpp
binaryTree tree;
tree.insert(1);
tree.inorderTraversal(); // Output: 1
cout << tree.getHeight(); // Output: 1
```

### Scenario 3: Random Insertion Effects
Due to random placement:
```cpp
binaryTree tree;
tree.insert(1);
tree.insert(2);
tree.insert(3);
```
Could result in different structures each run.

## 8. Complexity Analysis

### Time Complexity Detailed Breakdown

#### Basic Operations
| Operation | Average Case | Worst Case | Best Case | Notes |
|-----------|--------------|------------|----------|-------|
| Insert | O(log n) | O(n) | O(1) | Depends on tree balance |
| Find Height | O(n) | O(n) | O(1) | Must visit all nodes |
| Level Order | O(n²) | O(n²) | O(n²) | Current implementation |

#### Traversal Operations
| Traversal Type | Time | Space | Notes |
|----------------|------|-------|-------|
| Inorder | O(n) | O(h) | h = height |
| Preorder | O(n) | O(h) | Recursive stack |
| Postorder | O(n) | O(h) | Recursive stack |
