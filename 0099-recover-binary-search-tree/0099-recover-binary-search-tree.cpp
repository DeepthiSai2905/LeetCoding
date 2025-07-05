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
    void inorderTrav(TreeNode* root, vector<TreeNode*>&inOrder) {
        if(!root) return ;
        inorderTrav(root->left,inOrder);
        inOrder.push_back(root);
        inorderTrav(root->right,inOrder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inOrder;
        inorderTrav(root, inOrder);
        // now find first,second nodes to swap
        // when first is NULL, it is first anamoly
        TreeNode* prev=NULL,*first=NULL,*second=NULL;
        for(int i=0;i<inOrder.size();i++){
            if(prev && prev->val >= inOrder[i]->val){
                if(!first) {
                    first = prev;
                    second=inOrder[i];
                }
                else{
                    second=inOrder[i];
                }
            }
            prev=inOrder[i];
        }
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};