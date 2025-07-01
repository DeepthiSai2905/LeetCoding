class Solution {
public:
    bool isPalindrome(string s,int i,int j) {
        int n=s.length();
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; j--;
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                // delete either one - check which one could fit
              return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
            i++; j--; // move pointers
        }
        return true;
    }
};