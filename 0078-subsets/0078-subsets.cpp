class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // no recursion
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>path;
        res.push_back({});
        for(int i=0;i<n;i++){
            int resSize = res.size();
            for(int j=0;j<resSize;j++){
                vector<int>path=res[j];
                path.push_back(nums[i]);
                res.push_back(path);
            }
        }
        return res;
    }
};