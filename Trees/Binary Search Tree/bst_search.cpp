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
    // In BST search, conditions are mutually exclusive. Using else if ensures only 
    // one recursive call is made and guarantees a return value on all paths.
    
    // GOLDEN RULE:
    // Use multiple ifs only when multiple conditions can be true.
    // Use else if when only one condition can be true.
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
    if(root == nullptr) return false;
    if(root->data == data) return true;

    else if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
int main(){
    Node* root = nullptr;
    buildBST(root);
    inorder(root);
    cout << "35 found in tree: " << (search(root, 35) ? "Yes" : "No") << endl;
    cout << "40 found in tree: " << (search(root, 35) ? "Yes" : "No") << endl;


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
