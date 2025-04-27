class Solution {
public:
    bool isBoundary(int i,int j,int m,int n){
        return (i==0 || i==m-1) || (j==0 || j==n-1);
    }
    void dfs(vector<vector<char>>& board, int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O') return ;
        board[i][j]='C';

        dfs(board,i-1,j,m,n);
        dfs(board,i+1,j,m,n);
        dfs(board,i,j-1,m,n);
        dfs(board,i,j+1,m,n);
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