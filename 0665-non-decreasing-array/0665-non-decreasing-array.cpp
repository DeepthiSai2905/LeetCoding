class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i=0, n=nums.size();
        int count=0;
        while(i<n-1){
            if(nums[i]>nums[i+1]){
                count++;
                if(count>1) return false;
                if(i>0 && nums[i-1]>nums[i+1]){
                    nums[i+1]=nums[i];
                }
                else {
                    nums[i]=nums[i+1];
                }
            }
            i++;
        }
        
        return true;


    }
};