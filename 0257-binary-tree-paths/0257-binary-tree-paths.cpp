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
    void binaryTreePaths(TreeNode* root, vector<string>&v, string s){
        if(root==NULL) return ;
        if(!root->left && !root->right){
             s+=to_string(root->val);
             v.push_back(s);
             return ;
        }
        else s+=to_string(root->val)+"->";
        binaryTreePaths(root->left, v,s);
        binaryTreePaths(root->right, v,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        binaryTreePaths(root,v,"");
        return v;
    }
};