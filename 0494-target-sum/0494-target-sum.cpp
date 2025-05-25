class Solution {
public:
    int isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                int notake=prev[j];
                int take=0;
                if(arr[i-1]<=j) take = prev[j-arr[i-1]];
                curr[j]=take + notake;
            }
            prev=curr;
        }
        return prev[sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(abs(target)>sum || (sum+target)%2!=0) return 0;
        int resultSum = (sum+target)/2;
        return isSubsetSum(nums, resultSum);
    }
};