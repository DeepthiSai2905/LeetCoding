class Solution {
public:
    void checkIslandDFS(vector<vector<int>>& grid2, int i,int j){
        int m=grid2.size();
        int n=grid2[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]==0) return ;
        grid2[i][j]=0;
        checkIslandDFS(grid2,i-1,j);
        checkIslandDFS(grid2,i+1,j);
        checkIslandDFS(grid2,i,j-1);
        checkIslandDFS(grid2,i,j+1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int m=grid2.size();
        int n=grid2[0].size();
        int count=0;
        /*
           1. if grid2 has 1 and grid1 has 0 - eliminate that whole chunk of 1s in grid2
           2. now count all chunks of 1s in grid2
        */
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && grid1[i][j]==0){
                    checkIslandDFS(grid2,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    count++;
                    checkIslandDFS(grid2,i,j);
                }
            }
        }
       return count;
    }
};