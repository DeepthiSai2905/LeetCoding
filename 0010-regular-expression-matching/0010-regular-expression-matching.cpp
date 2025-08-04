class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=true; //empty string
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                // go 2 steps back
                dp[0][j]=dp[0][j-2];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    // 0 1
                    // 0 1 case - curr char at src == prev char of * in p
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){ 
                        dp[i][j]=dp[i-1][j] || dp[i][j-2];
                    }
                    // 0 caseis always available and will 2 steps back
                    else  dp[i][j]=dp[i][j-2]; // only 0 case
                }
                else{ // character
                   // check if they match
                   if(p[j-1]==s[i-1] || p[j-1]=='.'){ 
                    /* if . no need to match as it can 
                    match with any character(considered matched) */
                    // matched - left diag
                      dp[i][j]=dp[i-1][j-1];
                   }
                   else{
                      dp[i][j]=false;
                   }

                }
            }
        }
        return dp[m][n];
        
    }
};