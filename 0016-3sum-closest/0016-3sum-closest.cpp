class Solution {
public:
    int threeSumClosest(vector<int>& A, int B) {
        int n=A.size();
        int minDiff=INT_MAX;
        int nearestSum=0;
        sort(A.begin(),A.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum = A[i]+A[j]+A[k];
                int currDiff = abs(sum-B);
                
                if(currDiff==0) return sum;
                if(currDiff<minDiff) {
                    minDiff=currDiff;
                    nearestSum=sum;
                }
                if(sum<B){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return nearestSum;
    }
};