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
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        TreeNode* node=root;
        while(node->right){
            node=node->right;
        }
        node->right=root->left;
        root->left=NULL;
    }
};