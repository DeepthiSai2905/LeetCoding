class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>curr(n,0);
        vector<int>prev(n,1);
        prev[0]=1, curr[0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
             // dp[i][j]=dp[i-1][j]+dp[i][j-1];
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    
    }
};