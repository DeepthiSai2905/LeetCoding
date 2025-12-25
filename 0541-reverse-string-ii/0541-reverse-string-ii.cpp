class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i=0;
        string result;
        while(i<n){
            if(i+2*k > n){ // last set
               int remStrlen = n-i; // leftover string
               if(remStrlen<k){
                 reverse(s.begin()+i, s.end()); // reverse all
               }
               else{
                reverse(s.begin()+i, s.begin()+i+k); // reverse first k
               }
                result+=s.substr(i);
                break;
            }
            else{
                // take 2k characters, reverse first k
                reverse(s.begin()+i,s.begin()+i+k);
                i+=2*k;
            }
        }
        return s;
    }
};