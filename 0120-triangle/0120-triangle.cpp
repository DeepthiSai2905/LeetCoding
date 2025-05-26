class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        for(int i=1;i<m;i++){
            int n=triangle[i].size();
            for(int j=0;j<n;j++){
                int up = (j<triangle[i-1].size()) ? triangle[i-1][j] : INT_MAX;
                int leftdiag = (j>0) ? triangle[i-1][j-1] : INT_MAX;
                triangle[i][j]+=min(up,leftdiag);
            }
        }
        int res=INT_MAX;
        int n=triangle[m-1].size();
        for(int j=0;j<n;j++){
            res=min(res,triangle[m-1][j]);
        }
        return res;
    }
};