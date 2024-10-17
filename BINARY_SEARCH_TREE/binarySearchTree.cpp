#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}
};
class binarySearchTree{
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
    public:
    
        binarySearchTree(): root(nullptr){}

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
                if(value < current->data)
                    current = current->left;
                else
                    current = current-> right;
            }
            if(value < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }   
    }
    void inordertraversal() {
            inorder(root);
            cout<<endl;
        }

        void preordertraversal() {
            preorder(root);
            cout<<endl;
        }

        void postordertraversal() {
            postorder(root);
            cout<<endl;
        }
};

int main(){
    binarySearchTree tree;

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
