class Solution {
public:
    int findOccurence(vector<int>& nums, int target, int i,int j, bool firstOcc){
        int res = -1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                res=mid;
                if(firstOcc) j=mid-1;
                else i=mid+1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;
        int first = findOccurence(nums,target,i,j,true);
        int last = findOccurence(nums,target,i,j,false);
        return {first,last};
    }
};