class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0, j=m*n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int midR=(mid/n), midC=(mid%n);
            if(matrix[midR][midC]==target){
                return true;
            }
            else if(matrix[midR][midC]<target){
                i=mid+1;
            }
            else j=mid-1;

        }
        return false;
    }
};