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
    void rightSideViewDFS(TreeNode* root,vector<int>&res,int level){
        if(!root) return ;
        if(res.size()==level){
            res.push_back(root->val);
        }
        else res[level]=root->val;
        rightSideViewDFS(root->left, res,level+1);
        rightSideViewDFS(root->right, res,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        int level=0;
        rightSideViewDFS(root,res,level);
        return res;
    }
};