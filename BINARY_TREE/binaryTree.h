#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include"binaryTreeADT.h"
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree: public BinaryTreeADT{
    private:
        Node* root;

        void inorder(Node* node) const 
        {
            if(node != nullptr){
                inorder(node->left);
                cout<<node->data<<" ";
                inorder(node->right);
            }
        }

        void preorder(Node* node) const 
        {
            if(node != nullptr){
                cout<<node->data<<" ";
                preorder(node->left);
                preorder(node->right);
            }
        }

        void postorder(Node* node) const 
        {
            if(node != nullptr){
                postorder(node->left);
                postorder(node->right);
                cout<<node->data<<" ";
            }
        }
    
    public:
        BinaryTree(): root(nullptr){}

        void insert(int value) override{
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
            }
            else{
                Node* current = root;
                Node* parent = nullptr;

                while (current!=nullptr)
                {
                    parent = current;
                    if(value < current->data){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }
                if(value < parent->data)
                    parent->left = newNode;
                else
                    parent->right = newNode;
                
            }
        }

        void inordertraversal() const override {
            inorder(root);
            cout<<endl;
        }

        void preordertraversal() const override {
            preorder(root);
            cout<<endl;
        }

        void postordertraversal() const override {
            postorder(root);
            cout<<endl;
        }
};
 
#endif 