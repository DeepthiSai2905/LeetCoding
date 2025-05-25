class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1,false);
        prev[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                bool notake=prev[j];
                bool take=false;
                if(arr[i-1]<=j) take = prev[j-arr[i-1]];
                curr[j]=take || notake;
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0) return false;
        return isSubsetSum(nums,sum/2);
    }
};