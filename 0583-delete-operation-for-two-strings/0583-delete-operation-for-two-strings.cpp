class Solution {
public:
    int longestCommonSubsequence(string text1, string text2,int m,int n) {
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        prev[0]=0; curr[0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n=word2.length();
        int lcs = longestCommonSubsequence(word1,word2,m,n);
        return (m-lcs)+(n-lcs);

    }
};