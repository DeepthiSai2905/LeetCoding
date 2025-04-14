class Solution {
public:
    bool isBipartiteHelper(vector<vector<int>>& adj, vector<int>&vis, int src){
        for(auto adjNode:adj[src]){
            if(vis[adjNode]==-1){
                vis[adjNode]=1-vis[src];
                if(!isBipartiteHelper(adj,vis,adjNode)) return false;
            }
            else if(vis[adjNode]==vis[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(!isBipartiteHelper(adj,vis,i)) return false;
            }
        }
        return true;
  }
};