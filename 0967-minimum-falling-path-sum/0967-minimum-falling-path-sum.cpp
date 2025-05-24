class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int res=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int top = matrix[i-1][j];
                int leftdiag = (j>0) ? matrix[i-1][j-1] : INT_MAX;
                int rightdiag = (j<n-1) ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j]+=min(top,min(leftdiag,rightdiag));
                
            }
        }
        for(int j=0;j<n;j++){
            res=min(res,matrix[n-1][j]);
        }
        return res;
    }
};