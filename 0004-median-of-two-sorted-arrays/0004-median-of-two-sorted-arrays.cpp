class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make m small - nums1 small
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int low=0,high=m;
        while(low<=high){
            int parX = low+(high-low)/2;
            int parY = (m+n)/2 - parX;
            double X1 = parX==0 ? INT_MIN : nums1[parX-1];
            double X2 = parY==0 ? INT_MIN : nums2[parY-1];
            double Y1 = parX==m ? INT_MAX : nums1[parX];
            double Y2 = parY==n ? INT_MAX : nums2[parY];
            if(X1<=Y2 && X2<=Y1){
                // right partition
                if((m+n)%2 ==0) return (min(Y1,Y2)+ max(X1,X2))/2;
                else return min(Y1,Y2);
            }
            else if(X1>Y2){
                high=parX-1;
            }
            else low=parX+1;
        }
        return -1;

    }
};