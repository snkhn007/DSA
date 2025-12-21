#include <iostream>
#include <queue>
#include <stack>
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

// Reverse Level Order Traversal (Line-wise)
void revlvlOrderTraversal(Node* root){
    cout<<"Reverse Level Order Traversal : "<<endl;
    // If the tree is empty, no traversal is needed
    if(root == nullptr) return;

    queue <Node*> q;
    stack <Node*> st;
    q.push(root);
    q.push(nullptr);
    // Process the queue until it becomes empty
    while(!q.empty()){       
        Node* temp = q.front();
        q.pop();
        // If we encounter nullptr, it means one level is completed
        if(temp == nullptr){
            if(!q.empty()){
                st.push(nullptr);
                q.push(nullptr);
            }
        }
        // if(temp == nullptr && !q.empty()){}  INCORRECT
        else{
            st.push(temp);
            if(temp->right != nullptr) q.push(temp->right);    
            if(temp->left != nullptr) q.push(temp->left);
        }
    }
    while(!st.empty()){
        if(st.top() == nullptr){
            cout<<endl;
            st.pop();
        }
        else{
            cout<<st.top()->data<<" ";
            st.pop();
        }
    }
}
int main(){
    Node* root = buildTree();
    revlvlOrderTraversal(root);
}
/*
Expected Output:

Reverse Level Order Traversal prints the tree levels from bottom to top,
while maintaining left-to-right order within each level.\

BFS = level order but 
revBFS != rev level order

For the input:
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Constructed Tree:
        1
      /   \
     2     3
    / \     \
   4   5     6

Output:
4 5 6
2 3
1
*/


/*
Why use nullptr instead of NULL?

- nullptr is a C++11 keyword that represents a pointer to "no object".
- It has its own type (std::nullptr_t), so it is type-safe.
- NULL is usually defined as 0, which can cause ambiguity in function overloads.
- nullptr avoids accidental misuse with integers.
- Best practice in modern C++ is to always use nullptr for pointers.

Rule:
Use nullptr for pointers.
Do NOT use NULL in modern C++ code.
*/
