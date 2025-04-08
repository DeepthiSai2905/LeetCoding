class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]<nums[j]) return nums[i];
            int mid = i+(j-i)/2;
            if(nums[mid]<nums[i]){
                j=mid;
            }
            else i=mid+1;
        }
        return nums[i];
    }
};