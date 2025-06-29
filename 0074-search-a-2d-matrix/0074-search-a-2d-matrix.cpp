class Solution {
public:
    int binarySearch(vector<int>arr,int target){
        int low=0, high=arr.size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        // traverse last column to find which row can have target 
        // apply binary search to last column to find target or immediate value which >=target (lower bound)

        int res=-1;
        int low=0, high=m-1;
        int targetRow=-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][n-1] == target) {
                targetRow=mid; break;
            } else if (matrix[mid][n-1] < target) {
                low = mid + 1;
            } else {
                targetRow=mid;
                high = mid - 1;
            }
        }
        if (targetRow == -1) return false;
        // binary search on targetRow to check for target
        int targetCol = binarySearch(matrix[targetRow],target);
        if(targetCol==-1) return false;
        return true;
    }
};