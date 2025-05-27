class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prod(n,1);
        for(int i=1;i<n;i++){
            prod[i]=nums[i-1]*prod[i-1];
        }
        int right=1;
        for(int i=n-2;i>=0;i--){
            right*=nums[i+1];
            prod[i]*=right;
        }
        return prod;
    }
};