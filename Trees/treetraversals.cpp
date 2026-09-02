#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *buildTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return nullptr;
    TreeNode *newNode = new TreeNode(x);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
int main()
{
    TreeNode *root = buildTree();
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
}