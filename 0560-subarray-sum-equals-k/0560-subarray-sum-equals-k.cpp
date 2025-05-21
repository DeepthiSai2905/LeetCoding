class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int n=nums.size();
       int presum=0,count=0;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
          presum+=nums[i];
          if(presum==k) count++;
          if(mp.find(presum-k)!=mp.end()){ // present
             count+=mp[presum-k];
          }
          mp[presum]++;
       }
       return count; 
    }
};