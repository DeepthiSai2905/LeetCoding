class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max_sum=nums[0], final_max_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_max_sum = max(curr_max_sum+nums[i], nums[i]);
            if(curr_max_sum > final_max_sum) final_max_sum=curr_max_sum;
        }
        return final_max_sum;
    }
};