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
    // lets do int based recursion
    int inorderTraverse(TreeNode* root){
        if(root==NULL) return INT_MAX;
        int left = inorderTraverse(root->left);
        if(left!=INT_MAX) return left;
        count--; // root
        if(count==0) {
            return root->val;
        }
        int right = inorderTraverse(root->right);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        result=INT_MAX;
        count=k;
        // inorder
        return inorderTraverse(root);
        
    }
};