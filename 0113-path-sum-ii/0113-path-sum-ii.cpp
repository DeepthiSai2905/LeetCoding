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
    void helperPathSum(TreeNode* root, int curr_sum, vector<int> &curr,vector<vector<int>>&res, int targetSum){
        if(root==NULL) return ;
        curr_sum+=root->val;
        curr.push_back(root->val);
        
        if(!root->left && !root->right && curr_sum==targetSum){
            res.push_back(curr);
        }
        else{
            helperPathSum(root->left,curr_sum,curr,res,targetSum);
            helperPathSum(root->right,curr_sum,curr,res,targetSum);
        }
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>>res;
        vector<int>curr;
        helperPathSum(root,0,curr,res,targetSum);
        return res;
    }
};