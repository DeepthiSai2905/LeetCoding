class Solution {
public:
    double myPow(double x, int n) {
        long k=n;
        if(k==0) return 1;
        if(k<0){
          x=1/x;
          k=-k;
        }  
        double res=1.0;
        while(k>0){
            if(k%2!=0) res*=x;  // odd
            x=x*x;
            k/=2;
        }
        return res;
    }
};