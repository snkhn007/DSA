#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        // Assign the parameter data to the current object’s data using this keyword
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// Builds a binary tree using recursive input
// -1 indicates a null (empty) node
Node* buildTree() {
    int data;
    cout << "Enter data: "<<endl;
    cin >> data;

    // Base case: if input is -1, this node is NULL
    if (data == -1) {
        return nullptr;
    }

    // Create a new node with the given data
    Node* root = new Node(data);

    // Recursively build the left and right subtrees
    cout<<"Enter data to the left of "<<data<<" :"<<endl;
    root->left = buildTree();
    cout<<"Enter data to the right of "<<data<<" :"<<endl;
    root->right = buildTree();

    return root;
}

// level order traversal with newlines
void lvlOrderTraversal(Node* root){
    cout<<"Level Order Traversal : "<<endl;
    // If the tree is empty, no traversal is needed
    if(root == nullptr) return;

    queue <Node*> q;
    q.push(root);
    q.push(nullptr);
    // Process the queue until it becomes empty
    while(!q.empty()){       
        Node* temp = q.front();
        q.pop();
        // If we encounter nullptr, it means one level is completed
        if(temp == nullptr){
            if(!q.empty()){
                cout<<endl;
                q.push(nullptr);
            }
        }
        // if(temp == nullptr && !q.empty()){}  INCORRECT
        else{
            cout<<temp->data<<" ";
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);    
        }
    }
}
int main(){
    Node* root = buildTree();
    lvlOrderTraversal(root);
}
/*
Sample Input (Preorder with -1 as NULL):

1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Constructed Binary Tree:

        1
      /   \
     2     3
    / \     \
   4   5     6

Level Order Output:
1 2 3 4 5 6
*/