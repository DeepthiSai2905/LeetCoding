class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>result;
        vector<int>out(m,0);
        vector<vector<int>> revgraph(m);
        // reverse nodes
        for(int i=0;i<m;i++){
            for(int j : graph[i]){
                revgraph[j].push_back(i);
            }
            // count outdegree
            out[i]=graph[i].size();
        }
        queue<int>q;
        for(int i=0;i<m;i++){
             // push terminal nodes
            if(out[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front(); q.pop();
             // push that terminal node
            result.push_back(node);
            // push that safe node connected to terminal node
            for(auto adj: revgraph[node]){
                out[adj]--;
                if(out[adj]==0){
                    q.push(adj);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;

    }
};