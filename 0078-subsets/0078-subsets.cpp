class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<vector<int>>&res, int pivot, vector<int>&path){
        // if(pivot==nums.size()) {
        //     return ;
        // } i wont be able to add leaves (1,2,3),(2,3),(1,3)
        res.push_back(path);
        for(int i=pivot;i<nums.size();i++){
            path.push_back(nums[i]);
            subsetsHelper(nums,res,i+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        subsetsHelper(nums,res,0,path);
        return res;
    }
};