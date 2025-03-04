class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        int count=0;
        int medVal= (m+n)/2;
        int prev,median;
        while(count<=medVal){
            prev=median;
            if(i<m && j<n){
                if(nums1[i]<nums2[j]) {
                    median=nums1[i];
                    i++;
                }
                else{
                    median=nums2[j];
                    j++;
                }
            }
            else if(i<m && j==n){
                median=nums1[i]; i++;
            }
            else if(j<n && i==m){
                median=nums2[j]; j++;
            }
            count++;
        }
        if((m+n)%2==0) return (prev+median)/2.0;
        else return median/1.0;

    }
};