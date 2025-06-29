class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            if (nums[i] <= nums[j]) return nums[i];

            int mid=i+(j-i)/2;
            int prev = (mid-1);
            int next = (mid+1);
            if(mid>0 && mid<n-1 && nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[i]<=nums[mid]){ // left sorted
                i=mid+1;
            }
             else if(nums[mid]<=nums[j]){ // right sorted
                j=mid-1;
            }
        }
        return -1;
    }
};