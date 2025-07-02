class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length();
        if(m>n) return -1;
        const int mod = 1e9 + 7;
        long hashP=0,k=26;
        for(char ch:needle){
            hashP = (hashP*k+(ch-'a'+1))%mod;
        }
        
        long hashS=0;
        // long long power = pow(k, m-1);
        long long power = 1;
        for (int i = 1; i < m; i++) {
            power = (power * k) % mod;
        }
        for(int i=0;i<n;i++){
            long out=0;
            if(i>=m){ // actual sliding window
               // outgoing char
               char outChar = haystack[i-m];
                out = ((outChar-'a'+1)*power)%mod;
                hashS= (hashS-out+mod)%mod;
            }
            hashS = (hashS*k+(haystack[i]-'a'+1))%mod; // add current char
            
            if(i >= m - 1 && hashS==hashP) return i-m+1;
        }

        
        return -1;
    }
};