class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<bool>dp(n+1);
        dp[0]=true; //empty string
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                // go 2 steps back
                dp[j]=dp[j-2];
            }
        }
        for(int i=1;i<=m;i++){ 
            bool diagUp=dp[0];
            dp[0]=false;
            for(int j=1;j<=n;j++){
                bool temp=dp[j];
                if(p[j-1]=='*'){
                    // 0 1
                    // 0 1 case - curr char at src == prev char of * in p
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){ 
                        //dp[i][j]=dp[i-1][j] || dp[i][j-2];
                        dp[j]=dp[j] || dp[j-2];
                    }
                    // 0 caseis always available and will 2 steps back
                    // else  dp[i][j]=dp[i][j-2]; // only 0 case
                    else dp[j]=dp[j-2];
                }
                else{ // character
                   // check if they match
                   if(p[j-1]==s[i-1] || p[j-1]=='.'){ 
                    /* if . no need to match as it can 
                    match with any character(considered matched) */
                    // matched - left diag
                      dp[j]=diagUp;
                   }else{
                    dp[j]=false;
                   }
                }

                diagUp=temp;
            }
        }
        return dp[n];
        
    }
};