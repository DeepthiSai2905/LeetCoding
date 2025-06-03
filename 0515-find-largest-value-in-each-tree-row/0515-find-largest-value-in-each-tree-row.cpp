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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>res;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n=Q.size();
            int maxi=INT_MIN;
            while(n--){
                TreeNode* node=Q.front();
                Q.pop();
                if(maxi<node->val) maxi=node->val;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};