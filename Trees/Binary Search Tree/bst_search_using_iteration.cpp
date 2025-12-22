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
bool search(Node* root, int data){
    while(root != nullptr){
        if(root->data == data) return true;
        else if(root->data > data) root = root->left;
        else root = root->right;
    }
    return false;
}
int main(){
    Node* root = nullptr;
    buildBST(root);
    inorder(root);
    cout<<endl;
    cout << "35 found in tree: " << (search(root, 35) ? "Yes" : "No") << endl;
    cout << "40 found in tree: " << (search(root, 40) ? "Yes" : "No") << endl;
}

/*
Sample Input:
50 30 70 20 40 60 80 -1

Constructed Binary Search Tree:

            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80

Inorder Traversal Output:
20 30 40 50 60 70 80

*/
