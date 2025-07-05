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

    void inorderTravItr(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode*>st;
        // inorderTrav(root->left);
        // this takes care of rightsubtree left calls
        while(!st.empty() || root!=NULL){ 
            while(root){
                st.push(root);
                root=root->left;
            }
        
            root=st.top(); st.pop();
            //logic
            if(prev && prev->val >= root->val){
                if(!first) {
                    first = prev;
                }
                second=root;
            }
            prev=root;

            // inorderTrav(root->right);
            root=root->right;
        }
    }

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
        inorderTravItr(root);
        
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};