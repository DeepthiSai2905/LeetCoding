class Solution {
public:
    int minDistanceRec(string word1, string word2, int m, int n) {
        vector<int>dp(n+1,0);
        for(int j=0;j<=n;j++) dp[j]=j;
        for(int i=1;i<=m;i++){
            int diagUp=dp[0];
            dp[0]=i;
            for(int j=1;j<=n;j++){
                int temp=dp[j];
                if(word1[i-1]==word2[j-1]){
                    dp[j]=diagUp;
                }
                else{
                    // dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    dp[j]=1+min(diagUp,min(dp[j],dp[j-1]));
                }
                diagUp=temp;
            }
        }
        return dp[n];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        return minDistanceRec(word1,word2,m,n);
    }
};