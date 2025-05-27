class Solution {
public:
    int lcs(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
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
    int minInsertions(string s) {
        // length - length of longest palin subseq
        int len=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        return len-lcs(s,rev);
    }
};