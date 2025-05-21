class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int maxLen=0;
        // map presum to its first occurence index
        int presum=0;
        for(int i=0;i<n;i++){
            presum+=(nums[i]==0 ? -1:1);
            if(mp.find(presum)!=mp.end()){
                maxLen=max(maxLen,i-mp[presum]);
            }
            else{
                mp[presum]=i;
            } 

        }
        return maxLen;
    }
};