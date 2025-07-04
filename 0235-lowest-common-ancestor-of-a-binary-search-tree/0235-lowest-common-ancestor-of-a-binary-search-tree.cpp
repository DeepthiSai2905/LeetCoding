/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = p->val;
        int u = q->val;
        if(u < l) swap(l,u); // u bigger element out of both
        while(true){
            if(root->val > u) root = root->left;
            else if(root->val < l) root = root->right;
            else return root;
        }
    }
};