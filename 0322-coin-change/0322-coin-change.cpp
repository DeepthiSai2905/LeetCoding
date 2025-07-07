class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n][amount+1];
        // take first coin and check for amount
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                // no take
                int notake=dp[i-1][j];
                // take
                int take=INT_MAX;
                // here dp[i][j-coins[i]] can be INT_MAX
                if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,notake);
            }
        }
        return dp[n-1][amount] == INT_MAX ? -1: dp[n-1][amount];
    }
};