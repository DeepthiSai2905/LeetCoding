class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); // considering m small
        int n=nums2.size();
        if(m>n) return intersect(nums2,nums1);
        vector<int>result;
        unordered_map<int,int>mp;
        for(int num:nums1) mp[num]++;
        for(int ele:nums2){
            if(mp[ele]>0){
                result.push_back(ele);
                mp[ele]--;
            }
        }
        return result;
    }
};