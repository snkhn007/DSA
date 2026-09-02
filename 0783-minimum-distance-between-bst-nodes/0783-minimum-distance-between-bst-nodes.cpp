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
    void minDiff(TreeNode* root, int &diff, int &prev){
        if(root == nullptr) return;
        // if(diff > abs(root->val - prev)) diff = abs(root->val - prev);
        minDiff(root->left, diff, prev);
        if(prev != -1) diff = min( diff, abs(root->val - prev));
        prev = root->val;
        minDiff(root->right, diff, prev);
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        int prev = -1;
        minDiff(root, res, prev);
        return res;
        
    }
};