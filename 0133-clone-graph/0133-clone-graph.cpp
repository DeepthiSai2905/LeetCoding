/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*>mp;
        queue<Node*>Q;
        Node* clonedNode=new Node(node->val);
        mp[node]=clonedNode;
        Q.push(node); // iterate original graph
        while(!Q.empty()){
            Node* curr = Q.front(); Q.pop();
            for(Node* neigh: curr->neighbors){
                if(mp.find(neigh)==mp.end()){ // not found
                   // then only create cloned nodes
                   Node* clonedNeigh=new Node(neigh->val);
                   Q.push(neigh);
                   mp[neigh]=clonedNeigh;
                }
                // we have all neigh cloned nodes, create connections now
                mp[curr]->neighbors.push_back(mp[neigh]);
            }
        }
        return clonedNode;
    }
};