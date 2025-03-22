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
    bool hasPathSumHelper(TreeNode* root, int targetSum, int sum) {
        if(root==NULL) return false;
        sum+=(root->val);
        if(!root->left && !root->right) { // leaf
            if(sum==targetSum) return true;
        }
        return hasPathSumHelper(root->left,targetSum,sum) || 
        hasPathSumHelper(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return hasPathSumHelper(root,targetSum,sum);


    }
};