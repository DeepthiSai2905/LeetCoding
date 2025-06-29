class Solution {
public:
    long calcTime(vector<int>& piles,int speed){
        long time=0;
        for(int num:piles){
            int rem=(num%speed) ? 1:0;
            time+=(num/speed)+rem;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // speed k can be 1 to max element from piles
        int n=piles.size();
        int maxElement=-1;
        int res=-1;
        for(int num:piles) maxElement=max(maxElement,num);
        int low=1,high=maxElement;
        while(low<=high){
            int mid=low+(high-low)/2;
            long time = calcTime(piles,mid);
            if(time<=h){
                res=mid; // lesser value of k is possible so go left
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};