class Solution {
public:
    int helper(vector<int>&nums){
        int a, b=nums[0];
        for(int i=1;i<nums.size();i++){
            int val=max(nums[i]+a,b);
            a=b;
            b=val;
        }
        return b;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>res(10010);
        for(int num:nums){
            res[num]+=num;
        }
        return helper(res);
    }
};