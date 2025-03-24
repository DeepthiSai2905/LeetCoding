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
    void sumNumbersHelper(TreeNode* root, int curr_sum, int &ans){
        if(root==NULL) return ;
        curr_sum = curr_sum*10+root->val;
        if(!root->left && !root->right) ans+=curr_sum;
        sumNumbersHelper(root->left, curr_sum, ans);
        sumNumbersHelper(root->right, curr_sum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int curr_sum=0;
        int ans=0;
        sumNumbersHelper(root, curr_sum, ans);
        return ans;
    }
};