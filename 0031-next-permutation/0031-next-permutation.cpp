class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 2186495321 
        // from last find first element nums[i-1]<nums[i] 
        int n=nums.size();
        int j=n-1;
        while(j>0 && nums[j]<=nums[j-1]){
            j--;
        }
        // reached start - no next permutation
        if(j==0) {
            reverse(nums.begin(),nums.end());
            return ;
        }
        int index1=j-1; // number - 4
        int index2; // number - 5
        // find index2 element greater than nums[j]
        while(j<n && nums[j]>nums[index1] ){
            index2=j;
            j++;
        }
        swap(nums[index1],nums[index2]); // number becomes 2186594321 
        // reverse after index1 - 2186512349
        reverse(nums.begin()+index1+1, nums.end());
    }
};