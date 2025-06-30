class Solution {
public:
    
    int countKElements(vector<vector<int>>& matrix, int mid){
        int n=matrix.size();
        int row=n-1,col=0;
        int count=0;
        while(row>=0 && col<n){
            if(matrix[row][col]>mid){
                // that row do not have elements less than mid
                row--;
            }
            else{
                // all above row elements are <=(row value) so also <=8 
                // kind of count straight up from that row
                count+=(row+1); 
                col++; // move to next column
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while(low<=high){
            int mid = low+(high-low)/2;
            int count = countKElements(matrix,mid);
            if(count<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};