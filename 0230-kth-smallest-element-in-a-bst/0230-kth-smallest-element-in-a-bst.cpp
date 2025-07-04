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
    int result;
    int count;
    void inorderTraverse(TreeNode* root){
        if(root==NULL) return ;
       // System.print.outln(root->val). // example 1: k=2 -> 3124 (prints all even if added return in 23)
       // to skip traversal after k is 0, add below line
        if(result!=INT_MAX) return ; // conditional exit
        inorderTraverse(root->left);
        count--; // root
        if(count==0) {
            result = root->val;
            return ; // wtever goes in comes out of recrusion stack 
        }
        inorderTraverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        result=INT_MAX;
        count=k;
        // inorder
        inorderTraverse(root);
        return result;
        
    }
};