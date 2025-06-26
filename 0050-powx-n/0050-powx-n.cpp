class Solution {
public:
    double myPow(double x, int N) {
        if(N==0 || x==1) return 1;
        long long n=N;
        if(n<0) { 
            x=1/x; 
            n=-n;
        }
        double powerVal = myPow(x,n/2);
        if(n%2==0){ // even
           return powerVal*powerVal;
        }
        return powerVal*powerVal*x;
    }
};