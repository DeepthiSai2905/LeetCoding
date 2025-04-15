class Solution {
public:
    void allPathsSourceTargetHelper(vector<vector<int>>& graph,vector<bool>& vis,
         vector<vector<int>>& res,int src,int target,vector<int>& currpath){  
            currpath.push_back(src);
            if(src==target){
                res.push_back(currpath);
            }
            for(auto adjNode:graph[src]){
                allPathsSourceTargetHelper(graph,vis,res,adjNode,target,currpath);
            }
            currpath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // path from 0 to n-1
        vector<vector<int>>res;
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<int>currpath;
        allPathsSourceTargetHelper(graph,vis,res,0,n-1,currpath);
            
        return res;
    }




















    // void findAllPaths(vector<vector<int>>&res,vector<vector<int>>& graph,vector<int>&vis,int src,int goalNode,vector<int>&currPath){
    //     if(goalNode==currPath.back()){
    //         res.push_back(currPath); return ;
    //     }
    //     if(vis[src]) return ;
    //     vis[src]=true;
    //     for(int neigh:graph[src]){
    //         currPath.push_back(neigh);
    //         findAllPaths(res,graph,vis,neigh,goalNode,currPath);
    //         currPath.pop_back();
    //     }
    //     vis[src]=false;
    // }
    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //     vector<vector<int>>res;
    //     int n=graph.size();
    //     vector<int>vis(n,false);
    //     vector<int>currPath;
    //     int src=0; int goalNode=n-1;
    //     currPath.push_back(0);
    //     findAllPaths(res,graph,vis,src,goalNode,currPath);
    //     return res;
    // }
};