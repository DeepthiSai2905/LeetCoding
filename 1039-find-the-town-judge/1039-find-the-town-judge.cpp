class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+1,0); // O(V) space

        for(auto edge:trust){ // o(E) time
            int a=edge[0],b=edge[1]; // a->b
            degree[b]+=1;
            degree[a]-=1;
        }
        for(int i=1;i<=n;i++){ // O(V) time
            if(degree[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};