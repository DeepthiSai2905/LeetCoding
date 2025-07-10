/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        // create clone of next pointers
        while(curr){
            // Node* copynode = 
            mp[curr]=new Node(curr->val); // deep copy
            // copycurr->next = copynode; // linking cloned nodes
            curr=curr->next;
            // copycurr = copycurr->next;
        }
        // handle random pointers now
        curr=head;
        while(curr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            // mp[curr]->random= curr->random ? mp[curr->random] : NULL;
            curr=curr->next;
        }
        return mp[head];
    }
};