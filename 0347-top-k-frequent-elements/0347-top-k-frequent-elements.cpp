class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<vector<int>>v(n+1);
        for(auto itr:mp){ // O(n)
            v[itr.second].push_back(itr.first);
        }
        for(int i=n;i>0 && result.size()<k;i--){ // o(n)
            for(auto num: v[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};