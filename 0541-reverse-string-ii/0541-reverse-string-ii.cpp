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
                // take 2k characters
                string word1 = s.substr(i,k);
                string word2 = s.substr(i+k,k);
                reverse(word1.begin(),word1.end());
                result+=word1;
                result+=word2;
                i+=2*k;
            }
        }
        return result;
    }
};