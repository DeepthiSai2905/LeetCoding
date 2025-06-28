class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); // considering m small
        int n=nums2.size();

        if(m>n) intersection(nums2,nums1);
        vector<int>result;
        unordered_set<int>s(nums1.begin(),nums1.end());
        for(int num:nums2){
            if(s.find(num)!=s.end()){
                s.erase(num);
                result.push_back(num);
            }
        }
        return result;
    }
};