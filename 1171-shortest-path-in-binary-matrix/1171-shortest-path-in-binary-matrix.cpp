class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        if(mat[0][0]==1 || mat[n-1][n-1]==1) return -1;
        queue<pair<int,int>>Q;
        Q.push({0,0});
        mat[0][0]=1;
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            if (x == m-1 && y == n-1) return mat[x][y]; 
            vector<int>dir={-1, 0, 1, 1, 0, -1, -1, 1, -1, 0};
            for(int i=0;i<9;i++){
                int dx = x+dir[i];
                int dy = y+dir[i+1];
                bool isValid = (dx>=0 && dx<m && dy>=0 && dy<n);
                if(isValid && mat[dx][dy]==0){
                    mat[dx][dy]=1+mat[x][y];
                    Q.push({dx,dy});
                }
            }
        }
        return -1;
        
    }
};