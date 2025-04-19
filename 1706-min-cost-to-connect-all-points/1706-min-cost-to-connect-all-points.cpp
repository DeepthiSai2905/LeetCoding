class Solution {
public:
    class DisjointSet {
        vector<int>rank,parent,size;
        public:
               DisjointSet(int n){
                //   rank.resize(n+1,0);
                  size.resize(n+1,0);
                  parent.resize(n+1);
                  for(int i=0;i<n;i++) parent[i]=i;
               }
               int findUPar(int u){
                  if(u==parent[u]) return u;
                  return parent[u]=findUPar(parent[u]);
               }
               void UnionBySize(int u,int v){
                  int ulti_u = findUPar(u);
                  int ulti_v = findUPar(v);
                  if(ulti_u < ulti_v){
                    parent[ulti_u]=ulti_v;
                    size[ulti_v]+=size[ulti_u];
                  }
                  else{
                    parent[ulti_v]=ulti_u;
                    size[ulti_u]+=size[ulti_v];
                  }
               }
               void UnionByRank(int u,int v){
                  int ulti_u = findUPar(u);
                  int ulti_v = findUPar(v);
                  if(ulti_u < ulti_v){
                    parent[ulti_u]=ulti_v;
                  }
                  else if(ulti_u > ulti_v){
                    parent[ulti_v]=ulti_u;
                  }
                  else{
                    parent[ulti_v]=ulti_u;
                    rank[ulti_u]++;
                  }
               }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){ // connect point to every other point 
                int wt = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                edges.push_back({wt,{i,j}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int resultCost=0;
        for(auto it:edges){
            int wt=it.first;
            pair<int,int> edge = it.second;
            int u=edge.first, v=edge.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){ // disconnected
               resultCost+=wt;
               ds.UnionBySize(u,v); // add into spanning graph
            }
        }
        return resultCost;
    }
};