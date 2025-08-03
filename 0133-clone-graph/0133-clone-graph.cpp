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
    void dfs(Node* curr, unordered_map<Node*, Node*>&mp){
        // base
        if(mp.find(curr)!=mp.end()) return ; // node present
        // logic
        Node* clonedNode=new Node(curr->val);
        mp[curr]=clonedNode;
        for(Node* neigh: curr->neighbors){
            // then only create cloned nodes
            dfs(neigh, mp);
            // we have all neigh cloned nodes, create connections now
            mp[curr]->neighbors.push_back(mp[neigh]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*>mp;
        dfs(node,mp);
        return mp[node];
    }
};