class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        // sort and then take sum of 1st elements in pairs(min of 2 numbers)
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};