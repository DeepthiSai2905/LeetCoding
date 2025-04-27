class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>&vis){

        vis[i]=true;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(isConnected,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int count=0;
        vector<bool>vis(m,false);
        for(int i=0;i<m;i++){
                if(!vis[i]){
                    count++;
                    dfs(isConnected,i,vis);
                }
        }
        
        return count;
    }
};