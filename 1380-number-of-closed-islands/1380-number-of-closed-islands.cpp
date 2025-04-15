class Solution {
public:
    void dfsUtil(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 || j<0 || i>m-1 || j>n-1 || grid[i][j]==1) return ;
        grid[i][j]=1;
        dfsUtil(grid,i+1,j,m,n);
        dfsUtil(grid,i-1,j,m,n);
        dfsUtil(grid,i,j+1,m,n);
        dfsUtil(grid,i,j-1,m,n);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        // handle edges with values 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfsUtil(grid,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                    dfsUtil(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};