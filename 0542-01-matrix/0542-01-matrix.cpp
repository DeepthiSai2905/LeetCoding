class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>Q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) Q.push({i,j});
                else mat[i][j]=INT_MAX;
            }
        }
        while(!Q.empty()){
            auto [x,y] = Q.front(); Q.pop();
            vector<int>dir={-1,0,1,0,-1};
            for(int i=0;i<4;i++){
                int dx = x+dir[i];
                int dy = y+dir[i+1];
                bool isValid = (dx>=0 && dx<m && dy>=0 && dy<n);
                if(isValid && mat[dx][dy]>1+mat[x][y]){
                    mat[dx][dy]=1+mat[x][y];
                    Q.push({dx,dy});
                }
            }
        }
        return mat;
    }
};