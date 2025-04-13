class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOrange = 0, min_time = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>rottenOrange;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    rottenOrange.push({i, j});
                else if(grid[i][j] == 1)
                    freshOrange++;
            }
        }
        
        while(!rottenOrange.empty() && freshOrange>0){
            // incrementing time at each level
            min_time++;
            int qSize = rottenOrange.size();
            for(int i = 0; i < qSize; i++){
                auto [x, y] = rottenOrange.front();
                rottenOrange.pop();
                if(x > 0 && grid[x - 1][y] == 1) { // up
                    freshOrange--;
                    grid[x - 1][y] = 2;
                    rottenOrange.push({x - 1, y});
                }
                if(y > 0 && grid[x][y - 1] == 1) { // left
                    freshOrange--;
                    grid[x][y - 1] = 2;
                    rottenOrange.push({x , y - 1});
                }
                if(x < m - 1 && grid[x + 1][y] == 1) { // down
                    freshOrange--;
                    grid[x + 1][y] = 2;
                    rottenOrange.push({x + 1, y});
                }
                if(y < n - 1 && grid[x][y + 1] == 1) { // right
                    freshOrange--;
                    grid[x][y + 1] = 2;
                    rottenOrange.push({x, y + 1});
                }
            }
        }
        
        return freshOrange == 0 ? min_time : -1;
    }
};