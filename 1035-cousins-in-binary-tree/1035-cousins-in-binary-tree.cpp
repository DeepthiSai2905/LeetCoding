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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool xExist=false; bool yExist=false;
            while(n--){
                TreeNode* curr=q.front(); q.pop();
                if(curr->val==x) xExist=true;
                if(curr->val==y) yExist=true;
                if(curr->left && curr->right){
                    if((curr->left->val==x && curr->right->val==y) || 
                    (curr->left->val==y && curr->right->val==x)){
                        return false;
                    }
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(xExist && yExist) return true;
        }
        return false;
    }
};