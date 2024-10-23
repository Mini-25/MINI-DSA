#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}
};

class binaryTree{
    private:
        Node* root;
        
        void inorder(Node* node){
            if(node != nullptr){
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }
        
        void preorder(Node* node){
            if(node != nullptr){
                cout << node->data << " ";
                preorder(node->left);
                preorder(node->right);
            }
        }
        
        void postorder(Node* node){
            if(node!= nullptr){
                postorder(node->left);
                postorder(node->right);
                cout << node->data << " ";
            }
        }

        int height(Node* node){
            if(node == nullptr)
                return 0;
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
        
        void levelOrder(Node* node){
            int h = height(node);
            for(int i = 1; i <= h; i++)
                printCurrentLevel(node, i);
        }

        void printCurrentLevel(Node* node, int level){
            if(node == nullptr)
                return;
            if(level == 1)
                cout << node->data << " ";
            else if(level > 1){
                printCurrentLevel(node->left, level-1);
                printCurrentLevel(node->right, level-1);
            }
        }

    public:
        binaryTree(): root(nullptr){}
    
        void insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr)
                root = newNode;
            else {
                Node* current = root;
                Node* parent = nullptr;
                while (current != nullptr)
                {
                    parent = current;
                    if(rand() % 2) // Randomly decide to go left or right
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
        
        void inorderTraversal() {
            inorder(root);
            cout << endl;
        }
        
        void preorderTraversal() {
            preorder(root);
            cout << endl;
        }
        
        void postorderTraversal() {
            postorder(root);
            cout << endl;
        }

        void levelOrderTraversal() {
            levelOrder(root);
            cout << endl;
        }

        int getHeight(){
            return height(root);
        }
};

int main(){
    binaryTree tree;

    // Inserting nodes into the tree
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "In-order Traversal: ";
    tree.inorderTraversal();
    // Example Output: 4 2 5 1 6 3 7

    cout << "Pre-order Traversal: ";
    tree.preorderTraversal();
    // Example Output: 1 2 4 5 3 6 7

    cout << "Post-order Traversal: ";
    tree.postorderTraversal();
    // Example Output: 4 5 2 6 7 3 1

    cout << "Level-order Traversal: ";
    tree.levelOrderTraversal();
    // Example Output: 1 2 3 4 5 6 7

    cout << "Height of Tree: " << tree.getHeight() << endl;
    // Example Output: 3

    return 0;
}
