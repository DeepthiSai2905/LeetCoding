class Solution {
public:
    bool isBoundary(int i,int j,int m,int n){
        return (i==0 || i==m-1) || (j==0 || j==n-1);
    }
    void dfs(vector<vector<char>>& board, int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='X') return ;
        board[i][j]='C';

        vector<int>dirs={-1,0,1,0,-1};
        for(int k=0;k<4;k++){
            int x= i+dirs[k];
            int y= j+dirs[k+1];
            int isValid = (x>=0 && x<m && y>=0 && y<n);
            if(isValid && board[x][y]=='O'){
                dfs(board,x,y,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && isBoundary(i,j,m,n)){
                    dfs(board,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='C'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                     board[i][j]='X';
                }
            }
        }
    }
};