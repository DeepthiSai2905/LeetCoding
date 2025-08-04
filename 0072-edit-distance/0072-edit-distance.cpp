class Solution {
public:
    int minDistanceRec(string word1, string word2, int m, int n) {
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for (int j = 0; j <= n; j++) prev[j] = j;
        for(int i=1;i<=m;i++){
            curr[0] = i;  // This corresponds to dp[i][0] (deleting all characters from word1)
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev=curr;
        }
        return prev[n];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        return minDistanceRec(word1,word2,m,n);
    }
};