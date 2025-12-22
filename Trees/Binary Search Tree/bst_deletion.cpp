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
Node* insertIntoBst(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertIntoBst(root->left, data);
    }
    else if(root->data < data){
        root->right = insertIntoBst(root->right, data);
    }
    return root;
}
void buildTree(Node* &root){
    int data;
    cin>>data;
    while( data != -1){
        root = insertIntoBst(root, data);
        cin>>data;
    }
}
void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* getMin(Node* root){
    if(root == nullptr) return nullptr;
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node* del(Node* root, int data){
    if(root == nullptr) return nullptr;
    if(root->data == data){
        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        // 1 child
        else if( root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if( root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 2 child
        else{
            Node* min = getMin(root->right);
            root->data = min->data;
            root->right = del(root->right, min->data);
            return root;

        }
    }
    else if(root->data > data){
        root->left = del(root->left , data);
    }
    else{
        root->right = del(root->right , data);
    }
    return root;

}
int main(){
    Node* root = nullptr;
    buildTree(root);
    inorder(root);
    cout<<endl;
    root= del(root, 50);
    inorder(root);
}