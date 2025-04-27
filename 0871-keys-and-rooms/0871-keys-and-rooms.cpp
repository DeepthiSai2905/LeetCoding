class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int src, vector<bool>&vis){
        vis[src]=true;
        for(int adjNode:rooms[src]){
            if(!vis[adjNode]){
                dfs(rooms,adjNode,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};