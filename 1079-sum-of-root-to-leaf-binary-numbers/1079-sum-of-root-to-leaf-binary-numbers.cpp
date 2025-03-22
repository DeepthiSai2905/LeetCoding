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
    void sumRootToLeafHelper(TreeNode* root,int curr_sum, int &res){
        if(root==NULL) return ;
        curr_sum = curr_sum*2 + root->val;

        if(!root->left && !root->right){// leaf node
           res+=curr_sum;
           return ;
        }
        sumRootToLeafHelper(root->left,curr_sum,res);
        sumRootToLeafHelper(root->right,curr_sum,res);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        sumRootToLeafHelper(root,0,res);
        return res;
    }
};