class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1,right=1,count=1;
        int n=nums.size();
        int prev=nums[0];
        while(right<n){
            if(nums[right]==prev){
                if(count<2){
                    count++;
                    nums[left++]=nums[right];
                }
            }
            else{
                prev=nums[right];
                count=1;
                nums[left++]=nums[right];
            }
            right++;

        }
        return left;
        
    }
};