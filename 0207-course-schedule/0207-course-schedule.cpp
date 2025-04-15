class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>indeg(numCourses,0);
        vector<int>adj[numCourses];
        queue<int>Q;
        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        for(int i=0; i<numCourses ;i++){
            if(indeg[i]==0){
                Q.push(i);
            }
        }
        int count=0;
        while(!Q.empty()){
            int node=Q.front(); Q.pop();
            count++;
            for(auto adjNode: adj[node]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0){
                    Q.push(adjNode);
                }
            }
        }
        return count==numCourses;
    }
};