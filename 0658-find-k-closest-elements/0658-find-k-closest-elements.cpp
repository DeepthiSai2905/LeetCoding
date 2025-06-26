class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-1;
        while(r-l+1>k){
            int distL = abs(x-arr[l]);
            int distR = abs(x-arr[r]);
            if(distL<distR) r--;
            else if(distL>distR) l++;
            else { // move pointer which has greater value 
              if(arr[l]>arr[r]) l++;
              else r--;
            }
        }
        vector<int>result;
        for(int i=l;i<=r;i++){
            result.push_back(arr[i]);
        }
        // time - o(n), space-o(1)
        return result;

    }
};