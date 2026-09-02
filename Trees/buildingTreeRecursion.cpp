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
int main()
{
    buildTree();
}