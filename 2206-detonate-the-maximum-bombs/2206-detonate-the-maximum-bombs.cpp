class Solution {
public:
    int dfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
        vis[src]=true;
        int count=1;
        for(auto adjNode:adj[src]){
            if(!vis[adjNode]){
                count+=dfs(adjNode,adj,vis);
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long  x = bombs[i][0]-bombs[j][0];
                long long  y = bombs[i][1]-bombs[j][1];
                long long  distance = (x*x + y*y);
                long long  r1 = bombs[i][2];
                long long r2 = bombs[j][2];
                if(distance <= r1*r1){
                    // first bomb can explode 2nd
                    adj[i].push_back(j);
                }
                if(distance  <= r2*r2){
                    // second bomb can explode 1st
                    adj[j].push_back(i);
                }
            }
        }
        int maxBombsExploded=0;
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            int bombsExploded = dfs(i,adj,vis);
            if(bombsExploded > maxBombsExploded) maxBombsExploded = bombsExploded;
        }
        return maxBombsExploded;
    }
};