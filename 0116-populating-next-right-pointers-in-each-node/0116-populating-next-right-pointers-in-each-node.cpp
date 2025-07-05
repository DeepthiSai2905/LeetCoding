/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfsConnect(Node* root){
        // preorder
        if(root->left==NULL) return ; // for level
        // logic
        // 1. connect leftchild to rightchild
        root->left->next=root->right;
        // 2. connect right of left node chunk to left of right node chunk 
        if(root->next){
            root->right->next = root->next->left;
        }
        dfsConnect(root->left);
        dfsConnect(root->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        dfsConnect(root);
        return root;
    }
};