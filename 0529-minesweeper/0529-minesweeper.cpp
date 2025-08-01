class Solution {
public:
    vector<vector<int>>dirs = {{1,0},{1,1},{0,1},{-1,1}, {-1,0},{-1,-1},{0,-1},{1,-1}};
    bool isValid(int x,int y, int m,int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int countMines(vector<vector<char>>& board, int x, int y,int m,int n){
        int mines=0;
        for(auto d: dirs){
            int newX = d[0]+x;
            int newY = d[1]+y; 
            if(isValid(newX,newY,m,n) && board[newX][newY]=='M') mines++;
        }
        return mines;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(), n=board[0].size();
        int clickx=click[0],clicky=click[1];
        if(board[clickx][clicky]=='M'){ // initial click is mine
            board[clickx][clicky]='X'; // reveal it
            return board;
        }
        queue<pair<int,int>>Q;
        Q.push({clickx,clicky});
        board[clickx][clicky]='B';
        while(!Q.empty()){
            auto curr = Q.front(); Q.pop();
            int x = curr.first, y = curr.second;
            
           // check for mines around all sides
            int mines=countMines(board, x, y,m,n);
            if(mines>0) {
                board[x][y]=mines+'0';
                continue;
            }
            // no mines then only explore neighbors
            for(auto d: dirs){
                int newX = x+d[0];
                int newY = y+d[1]; 
                if(isValid(newX,newY,m,n) && board[newX][newY]=='E') {
                    // make it B and push into Q
                    board[newX][newY]='B'; // make it visited
                    Q.push({newX,newY});
                }
            }
            
        }
        return board;
    }
};