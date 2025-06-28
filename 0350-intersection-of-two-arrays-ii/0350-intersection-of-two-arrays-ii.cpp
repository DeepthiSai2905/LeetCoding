class Solution {
public: // solution for sorted arrays
    int firstOccurence(vector<int>& nums, int target, int i,int j){
        int res = -1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                res=mid;
                j=mid-1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return res;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); // considering m small
        int n=nums2.size();
        if(m>n) return intersect(nums2,nums1);

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        // mlogn - search each element of smaller array in bigger array using binary search
        vector<int>result;
        int low=0,high=n-1;
        for(int num:nums1){
            int bsIndx = firstOccurence(nums2,num, low,high);
            if(bsIndx==-1) continue;
            low=bsIndx+1;
            result.push_back(num);
        }
        return result;
    }
};