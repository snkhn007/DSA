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
    int nodes(TreeNode* root){
        if(root == nullptr) return 0;
        int left = nodes(root->left);
        int right = nodes(root->right);
        return left+right+1;
    }
    int avg(TreeNode* root, int&cnt){
        if(root == nullptr) return 0;
        int left = avg(root->left, cnt);
        int right = avg(root->right, cnt);
        // avg includes the value of node as well ->
        int sum = left+right+root->val;
        int count = nodes(root);
        int avg = sum/count;
        if(avg == root->val) cnt++;
        // return avg;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        avg(root, cnt);
        return cnt;
        
    }
};