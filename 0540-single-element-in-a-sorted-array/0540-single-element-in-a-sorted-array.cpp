class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            // mid can be even or odd
            // mid is even, and nums[mid] == nums[mid + 1] → Single element is on the right.
            // mid is odd, and nums[mid] == nums[mid - 1] → Single element is on the right.
            // This is because pairs before the unique element start at even indices, and the pattern breaks at or after the unique element.
            if(mid>0 && mid<n-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            // intuition - either left or right have single element
            // 1122334 - right unique (mid=2, mid-1 is also 2)
            // 1123344 - left unique (mid=3, mid+1 is also 3)
            if(mid>0 && mid<n-1  && (mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid] == nums[mid - 1])){ // move right
                 i=mid+1;
            }
            else j=mid-1;
        }
        return nums[i];
    }
};