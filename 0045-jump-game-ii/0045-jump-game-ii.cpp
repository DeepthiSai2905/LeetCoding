class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        // using greedy - range method
        int l=0,r=0;
        int farthest;
        while(r<n-1){ // if n-1 or more, we reached destination
           // find farthest it can reach
            farthest=INT_MIN;
            for(int i=l;i<=r;i++){
              // find farthest to in current range to create next range
              farthest=max(farthest, i+nums[i]);
            }
            l=r+1; // move to next window
            jumps++;
            r=farthest;
        }
        return jumps;
    }
};