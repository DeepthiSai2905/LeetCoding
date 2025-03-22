/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front(); q.pop();
            if(curr==NULL){
                s+="#,";
            }
            else{
                s+=to_string(curr->val)+",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // cout<< s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        int pos = data.find(",");
        string token = data.substr(0,pos);
        data = data.substr(pos+1);

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // left child
            pos = data.find(",");
            token = data.substr(0,pos);
            data = data.substr(pos+1);
            if(token!="#"){
                curr->left=new TreeNode(stoi(token));
                q.push(curr->left);
            }

            // right child
            pos = data.find(",");
            token = data.substr(0,pos);
            data = data.substr(pos+1);
            if(token!="#"){
                curr->right=new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));