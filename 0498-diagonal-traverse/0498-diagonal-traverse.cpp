class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        bool botTotop=true;
        int i=0,j=0;
        vector<int>res;
        // down left dig = (i-1,j+1)
        while(res.size()<m*n){
            res.push_back(mat[i][j]);
            if(botTotop){
                
                if(j==n-1){ // last col - go down
                   i++;
                   botTotop=false;
                }
                else if(i==0){ // first row - go right
                   j++;
                   botTotop=false;
                }
                else{
                    // go top-right diag - (i-1,j+1)
                    i--;
                    j++;
                }

            }
            else{
                if(i==m-1){ // go right
                   j++;
                   botTotop=true;
                }
                else if(j==0){
                   i++;
                   botTotop=true;
                }
                else{
                    i++;
                    j--;
                }
            }
        }
        return res;
        
    }
};