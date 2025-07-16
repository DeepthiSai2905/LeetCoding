class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        int x=n-k;
        for(int i=0;i<x;i++){
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(),nums.begin()+x);
    }
};