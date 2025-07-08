class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            // that particular subarray maximum
            int maxi=arr[i];
            for(int j=1;j<=k && (i-j+1)>=0; j++){
                int curr=arr[i-j+1];
                maxi=max(curr,maxi);
                if(i-j>=0) dp[i]=max(dp[i],maxi*j + dp[i-j]);
                else dp[i]=max(dp[i],maxi*j);
            }
        }
        return dp[n-1];
    }
};