class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low=1,high=x;
        while(low<=high){
            int mid=low+(high-low)/2; // mid* mid can be out of bound for int
            long long square = 1LL * mid * mid; 
            if(square==x) return mid;
            else if(square<x) { // increase mid - go right
               low=mid+1;
            }
            else high=mid-1;
        }
        /*  why?? The loop runs while low <= high.

            Eventually, low becomes greater than high, so the loop stops.
            At this point:
            Every number less than or equal to high has a square ≤ x.
            Every number greater than or equal to low has a square > x
            So high is the last safe number — the biggest one that didn’t overshoot.

            Find the biggest number such that number * number <= x.
            high is the last value where mid * mid <= x. So, high is the floor of sqrt(x).
        */
        return high;
    }
};