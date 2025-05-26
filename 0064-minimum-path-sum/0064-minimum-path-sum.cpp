class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<m;i++) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<n;j++) grid[0][j]+=grid[0][j-1];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up = grid[i-1][j];
                int left = grid[i][j-1];
                grid[i][j]+=min(up,left);
            }
        }
        return grid[m-1][n-1];
    }
};