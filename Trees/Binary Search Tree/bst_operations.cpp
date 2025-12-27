#include <iostream>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node * left;
    Node * right;
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
    else if(root->data > data){
        root->left = insertIntoBst(root->left, data);
    } 
    else if (root->data < data){
        root->right = insertIntoBst(root->right, data);
    }
    return root;
}
void buildBst(Node* &root){
    int data ;
    cin>>data;
    while(data != -1){
        root = insertIntoBst(root, data);
        cin>>data;
    }
}
void lvlOrder(Node* root){
    if(root == nullptr) return;

    queue <Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == nullptr){
            if(!q.empty()){
                q.push(nullptr);
                cout<<endl;
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
    }
}
// Recursive search in BST
// Time Complexity: O(h)
// Space Complexity: O(h) due to recursion stack
bool search(Node* root, int data){
    if(root == nullptr) return false;
    else if(root->data == data) return true;
    else if(root->data > data) return search(root->left, data);
    else return search(root->right, data);
}
// Iterative search in BST
// Better than recursive because:
// - No recursion stack
// - Space Complexity: O(1)
// Time Complexity: O(h)
bool searchIterative(Node* root, int data){
    while(root != nullptr){
        if(root->data == data) return true;
        else if( root->data > data ) root = root->left;
        else root = root->right;
    }
    return false;
}
int getMin(Node* root){
    if(root == nullptr) return -1;
    while(root->left != nullptr){
        root = root->left;
    }
    return root->data;
}
Node * del(Node* root, int data){
    if(root == nullptr) return nullptr;
    else if(root->data == data){
        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        // Left Child
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Both childs
        else{
            // Find inorder successor (min in right subtree)
            int minVal = getMin(root->right);

            // Replace current node's data
            root->data = minVal;

            // Delete inorder successor
            root->right = del(root->right, minVal);

            return root;

            // // Alternative approach using inorder predecessor
            // int maxVal = getMax(root->left);
            // root->data = maxVal;
            // root->left = del(root->left, maxVal);
            // return root;
        }
    }
    else if(root->data > data) root->left = del(root->left, data);
    else return root->right = del(root->right, data);    
}
int main(){
    Node* root = nullptr;
    buildBst(root);
    lvlOrder(root);
    cout<<endl;
    cout<<"Element 50 is "<<(search(root, 50)? "present" : "not present")<<" in tree"<<endl;
    cout<<"Element 90 is "<<(search(root, 90)? "present" : "not present")<<" in tree"<<endl;

    cout<<"Element 50 is "<<(searchIterative(root, 50)? "present" : "not present")<<" in tree"<<endl;
    cout<<"Element 90 is "<<(searchIterative(root, 90)? "present" : "not present")<<" in tree"<<endl;

    cout<<"Minimum val in tree 50 30 70 20 40 60 80 -1: "<<getMin(root)<<endl;
    root = del(root, 50);
    lvlOrder(root);
}
// 50 30 70 20 40 60 80 -1
// Constructed Binary Search Tree:

//             50
//           /    \
//         30      70
//        /  \    /  \
//      20   40  60   80
