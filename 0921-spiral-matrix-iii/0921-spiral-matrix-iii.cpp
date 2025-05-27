class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>res;
        int count=0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 1;  
        int x = rStart, y = cStart;

        res.push_back({x, y});
        count++;
        
        while (count < rows*cols) {
            for (int d = 0; d < 4; d++) {
                int dx = directions[d].first;
                int dy = directions[d].second;

                for (int i = 0; i < steps; i++) {
                    x += dx;
                    y += dy;

                    if (x >= 0 && y >= 0 && x < rows && y < cols) {
                        res.push_back({x, y});
                        count++;
                    }
                }

                if (d % 2 == 1) steps++;
            }
        }
        return res;
    }
};