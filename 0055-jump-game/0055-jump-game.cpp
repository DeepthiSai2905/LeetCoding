class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int canMaxReach=0;
        for(int i=0;i<n;i++){
            if(i>canMaxReach) return false;
            canMaxReach = max(canMaxReach,i+nums[i]);
        }
        return true;
    }
};