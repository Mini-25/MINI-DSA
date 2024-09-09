#include <iostream>
#include "binaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;

    // Inserting the nodes into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inordertraversal();  
    // Output: 20 30 40 50 60 70 80

    cout << "Pre-order Traversal: ";
    tree.preordertraversal();  
    // Output: 50 30 20 40 70 60 80

    cout << "Post-order Traversal: ";
    tree.postordertraversal();  
    // Output: 20 40 30 60 80 70 50

    return 0;
}
