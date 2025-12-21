#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// Insert a value into BST (duplicates are ignored)
Node* insertInBST(Node* root, int data){
    // Empty tree
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = insertInBST(root->left, data);
    }
    if(root->data < data){
        root->right = insertInBST(root->right, data);
    }
    return root;
}
void buildBST(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertInBST(root, data);
        cin>>data;
    }
}

// inorder traversal
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root = nullptr;
    buildBST(root);
    inorder(root);

}

/*
Sample Input:
50 30 70 20 40 60 80 -1

Explanation:
The input is taken as a sequence of integers.
- Each value is inserted into the BST one by one.
- -1 indicates the end of input.
- Duplicate values (if any) are ignored.

Constructed Binary Search Tree:

            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80

Inorder Traversal Output:
20 30 40 50 60 70 80

Note:
Inorder traversal of a BST always prints values in sorted order.
*/
