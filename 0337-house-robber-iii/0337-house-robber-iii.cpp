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
    unordered_map<TreeNode*,int>m;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int total=0;
        if(m.find(root)!=m.end()) return m[root];
        if(root->left){
            total+= (rob(root->left->left)) + (rob(root->left->right));
        }
        if(root->right){
            total+= (rob(root->right->left)) + (rob(root->right->right));
        }
        int includeRoot = root->val+total;
        int excludeRoot = rob(root->left) + rob(root->right);
        return m[root]=max(includeRoot,excludeRoot);
    }
};