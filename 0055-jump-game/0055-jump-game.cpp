class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return true;
        queue<int>Q;
        unordered_set<int>s; // to aviod repeated computatinos in recursion
        Q.push(0);
        s.insert(0);
        while(!Q.empty()){
            int curr=Q.front(); Q.pop();
            for(int j=1;j<=nums[curr];j++){
                int newInd = curr+j;
                if(newInd==n-1) return true;
                if(!s.count(newInd)){
                    Q.push(newInd);
                    s.insert(newInd);
                }
            }
        }
        return false;
    }
};