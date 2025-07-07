class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // space optimisation 
        int n=coins.size();
        // int dp[n][amount+1];
        vector<int>curr(amount+1);
        vector<int>prev(amount+1);
        // take first coin and check for amount
        for(int j=0;j<=amount;j++){
            /*if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=INT_MAX;*/
             if(j%coins[0]==0) prev[j]=j/coins[0];
            else prev[j]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                // no take
                // int notake=dp[i-1][j];
                int notake=prev[j];
                // take
                int take=INT_MAX;
                // here dp[i][j-coins[i]] can be INT_MAX
                // if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX) take=1+dp[i][j-coins[i]];
                if(coins[i]<=j && curr[j-coins[i]]!=INT_MAX) take=1+curr[j-coins[i]];
                // dp[i][j]=min(take,notake);
                curr[j]=min(take,notake);
            }
            prev=curr;
        }
        // return dp[n-1][amount] == INT_MAX ? -1: dp[n-1][amount];
        return prev[amount] == INT_MAX ? -1: prev[amount];
    }
};