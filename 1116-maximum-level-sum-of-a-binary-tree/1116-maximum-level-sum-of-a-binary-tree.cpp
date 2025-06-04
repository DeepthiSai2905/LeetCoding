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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return -1;
        int maxSum=INT_MIN;
        int minLevel=0,level=0;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n=Q.size();
            int sum=0;
            level++;
            while(n--){
                TreeNode* node=Q.front();
                Q.pop();
                sum+=node->val;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            if(sum>maxSum){
                maxSum=sum;
                minLevel=level;
            }
        }
        return minLevel;

    }
};