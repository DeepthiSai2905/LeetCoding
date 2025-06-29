class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return true;
            }
            // add extra condition for duplicates elmination
            if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
            }
            else if(nums[mid]>=nums[i]){ // left side is sorted
                // check if target is in the left side
                // if yes, search in left side, else search in right side
                if(nums[i]<=target && nums[mid]>=target){
                    j=mid-1;
                }
                else i=mid+1;
            }
            else{ // right side is sorted
                // check if target is in the right side
                // if yes, search in right side, else search in left side
                if(nums[j]>=target && nums[mid]<=target){
                    i=mid+1;
                }
                else j=mid-1;
            }
        }
        return false;
    }
};