class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i=0;
        string result;
        while(i+2*k<n){
            reverse(s.begin()+i,s.begin()+i+k);
            i+=2*k;
        }
        int remStrlen = n-i; // leftover string
        
        if(remStrlen<k){
            reverse(s.begin()+i, s.end()); // reverse all
        }
        else{
        reverse(s.begin()+i, s.begin()+i+k); // reverse first k
        }
        return s;
    }
};