class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // exmapke: 3 6 8 10 - missing elements to left 
        // missing count=arr[mid]-mid-1
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int missingCount = arr[mid]-mid-1;
            if(missingCount<k){ // go right
               i=mid+1;
            }
            else j=mid-1;

        }
       // The kth missing number is found at left + k, where left is the smallest index where the missing count exceeds or equals k
        return i+k;
    }
};