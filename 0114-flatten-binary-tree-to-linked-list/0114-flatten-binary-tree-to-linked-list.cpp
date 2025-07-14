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
        // left side
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                // bring right subtree to left
                TreeNode* preced = curr->left;
                while(preced->right){
                    preced=preced->right;
                }
                // connect right subtree to right most node of left subtree
                preced->right=curr->right;
                // move left to right (we need linkedlist to right)
                curr->right=curr->left;
                curr->left=NULL;
            }
            // we no more have left subtrees
            curr=curr->right;
        }
        // tc - o(n), sc-o(1)
    }
};