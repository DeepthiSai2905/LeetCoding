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
    // now find first,second nodes to swap
    // when first is NULL, it is first anamoly
    TreeNode* prev=NULL,*first=NULL,*second=NULL;
    void inorderTrav(TreeNode* root) {
        if(!root) return ;
        inorderTrav(root->left);

        //logic
        if(prev && prev->val >= root->val){
            if(!first) {
                first = prev;
            }
            second=root;
        }
        prev=root;

        inorderTrav(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorderTrav(root);
        
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};