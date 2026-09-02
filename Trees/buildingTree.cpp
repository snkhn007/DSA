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
int main()
{
    TreeNode *root = new TreeNode(1);
    // TreeNode* node2 = new TreeNode(2);
    // TreeNode* node3 = new TreeNode(3);
    // TreeNode* node4 = new TreeNode(4);
    // TreeNode* node5 = new TreeNode(5);
    // root->left = node2;
    // root->right = node3;

    // node2->left = node4;
    // node2->right = node5;

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
}