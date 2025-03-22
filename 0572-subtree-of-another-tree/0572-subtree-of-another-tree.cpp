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
    bool isIdentical(TreeNode* r1, TreeNode* r2){
        // cout<< r1->val << r2->val << "  - r1,r2" <<endl;
        if(r1==NULL || r2==NULL) return r1==r2;
        return r1->val==r2->val && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if(isIdentical(root,subRoot)) return true;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            if(curr->val == subRoot->val){
                cout<< "curr - "<<curr->val <<endl;
                int val = isIdentical(curr,subRoot);
                cout<< val << "val" <<endl;
                if(val) return val;
            }
            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }
        return false;
    }
};