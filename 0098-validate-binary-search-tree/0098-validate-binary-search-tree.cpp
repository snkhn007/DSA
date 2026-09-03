/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool validate(TreeNode* root, int strt, int end){
    bool validate(TreeNode* root, long long  strt, long long end){
        if(root == nullptr) return true;
        if((root->val <= strt) || (root->val >= end)) return false;
        bool left = validate(root->left, strt, root->val);
        bool right = validate(root->right, root->val, end);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        // return validate(root, INT_MIN, INT_MAX);
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};