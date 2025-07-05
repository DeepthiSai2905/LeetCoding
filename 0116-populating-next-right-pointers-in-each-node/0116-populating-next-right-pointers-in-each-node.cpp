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
    Node* connect(Node* root) {
        if(!root) return root;
        Node* level=root;
        while(level->left){
            Node* curr=level;
            while(curr){
                // 1. connect leftchild to rightchild
                curr->left->next=curr->right;
                // 2. connect right of left node chunk to left of right node chunk 
                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                // 3. go to next 
                curr=curr->next;
            }
            level=level->left;
        }
        return root;
    }
};