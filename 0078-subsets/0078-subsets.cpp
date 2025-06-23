class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<vector<int>>&res, int index, vector<int>path){
        if(index==nums.size()) {
            res.push_back(path);
            return ;
        }
        // take - without backtracking
        vector<int>temp=path;
        temp.push_back(nums[index]);
        subsetsHelper(nums,res,index+1,temp);
        // no take
        subsetsHelper(nums,res,index+1,path);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        subsetsHelper(nums,res,0,path);
        return res;
    }
};