class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // // space optimisation 
        int n=coins.size();
        // int dp[n][amount+1];
        vector<unsigned long long>dp(amount+1);
        // take first coin and check for amount
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]= dp[j] + dp[j-coins[i]];
            }
        }
        return dp[amount];  
    }
};