class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i=0;
        string result;
        for(int i=0;i<n;i+=2*k){
            //  min(chars left in last window, k);
            int end = min(n-i, k);
            reverse(s.begin()+i,s.begin()+i+end);
        }
        return s;
    }
};