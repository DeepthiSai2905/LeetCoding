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
    vector<TreeNode*> pathP, pathQ;
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path){
        //base case
        if(root==NULL) return ;
        // after we got both path we dont need to iterate any furthur
        // if(pathP.size()>0 && pathQ.size()>0) return; // conditional exit
        //logic

        //action
        path.push_back(root);
        if(root==p){
            pathP=path;
            pathP.push_back(root);
        }
        if(root==q){
            pathQ=path;
            pathQ.push_back(root);
        }
        // recurse
        helper(root->left,p,q,path);
        helper(root->right,p,q,path);
        //backtrack
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute create path for both p,q
        // base case
        if(root==NULL) return NULL;
        vector<TreeNode*> path;
        helper(root,p,q,path);
        for(int i=0;i<pathP.size();i++){
            if(pathP[i]!=pathQ[i]){
                return pathP[i-1];
            }
        }
        return NULL;
    }
};