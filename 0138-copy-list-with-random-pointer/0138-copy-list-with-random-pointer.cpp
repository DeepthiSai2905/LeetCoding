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
//  can we create random pointers while creating next pointers? in first stage itself
        if(!head) return head;
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        // create clone of next pointers and random pointers
        while(curr){
             // deep copy of next node
            if (mp.find(curr) == mp.end()) {
                mp[curr] = new Node(curr->val);
            }
            // make next pointer links
            if (curr->next) {
                if (mp.find(curr->next) == mp.end()) {
                    // Clone the next node if not cloned yet
                    mp[curr->next] = new Node(curr->next->val);  
                }
                mp[curr]->next = mp[curr->next];  // Link next pointer
            }
            // create deep copy of random node if not present else make link
            if(curr->random){
                if(mp.find(curr->random)==mp.end()){ // not present
                   mp[curr->random] = new Node(curr->random->val);
                  
                }
                mp[curr]->random = mp[curr->random]; //just link
            }
            curr=curr->next;
        }
        return mp[head];
    }
};