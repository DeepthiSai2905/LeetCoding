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
    void smallestFromLeafHelper(TreeNode* root,string &curr, string &result){
        if(root==NULL) return ;
        curr+=(root->val+'a');
        if(!root->left && !root->right){
            string reversedString = curr;
            reverse(reversedString.begin(),reversedString.end());
            if(result.empty() || reversedString < result) result=reversedString;
        }
        else{
            smallestFromLeafHelper(root->left,curr,result);
            smallestFromLeafHelper(root->right,curr,result);
        }
        // curr.pop_back();
        curr=curr.substr(0,curr.length()-1);
    }
    string smallestFromLeaf(TreeNode* root) {
       string result,curr;
       smallestFromLeafHelper(root,curr,result);
       return result;
    }
};