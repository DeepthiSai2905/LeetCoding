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
    void sumOfLeftLeavesHelper(TreeNode* root, int &leftSum){
        if(root==NULL) return ;
        if(root->left && !root->left->left && !root->left->right){
            leftSum+=(root->left->val);
        }
        sumOfLeftLeavesHelper(root->left,leftSum);
        sumOfLeftLeavesHelper(root->right,leftSum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int leftSum=0;
        sumOfLeftLeavesHelper(root, leftSum);
        return leftSum;
    }
};