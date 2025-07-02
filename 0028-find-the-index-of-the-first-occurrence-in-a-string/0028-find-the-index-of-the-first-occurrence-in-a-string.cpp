class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length();
        int i=0,j=0;
        while(i<=n-m){
            if(haystack[i]==needle[0]){ // if found first char
               int k=i,j=0;
               while(haystack[k]==needle[j]){
                k++; j++;
                if(j==m) return i; // match found
               }
               // if match not found
               i++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};