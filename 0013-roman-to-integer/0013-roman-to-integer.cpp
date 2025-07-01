class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.length();
        int res=0;
        for(int i=1;i<n;i++){
            char prev = s[i-1];
            char curr = s[i];
            if(mp[prev]>=mp[curr]){
                res+=mp[prev];
            }
            else{
                res-=mp[prev];
            }
        } //  n-1 is not computed
        res+=mp[s[n-1]];

        return res;
    }
};