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
        Node* copyHead=new Node(head->val);
        mp[head]=copyHead;
        Node* copycurr=copyHead;
        // create clone of next pointers
        while(curr->next){
            Node* copynode = new Node(curr->next->val);
            mp[curr->next]=copynode; // deep copy
            copycurr->next = copynode; // linking cloned nodes
            curr=curr->next;
            copycurr = copycurr->next;
        }
        // handle random pointers now
        curr=head;
        while(curr){
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
        return copyHead;
    }
};