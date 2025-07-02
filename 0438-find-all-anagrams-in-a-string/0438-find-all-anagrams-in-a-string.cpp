class Solution {
public:
    bool checkAnagram(vector<int>scount,vector<int>pcount){
        for(int i=0;i<26;i++){
            if(scount[i]!=pcount[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        vector<int>result;
        // brute - sliding window - check each window for anagram
        vector<int>res;
        vector<int>pcount(26,0);
        vector<int>scount(26,0);
        for(char ch:p){
            pcount[ch-'a']++;
        }
        // first m elements only
        for(int i=0;i<m;i++){
            scount[s[i]-'a']++;
        }
        if(checkAnagram(scount,pcount)) result.push_back(0); // first window
        for(int i=m;i<n;i++){ // o(n)
            scount[s[i-m]-'a']--; // remove outgoing // next to this is first index of window
            scount[s[i]-'a']++; // add incoming
            if(checkAnagram(scount,pcount)){ // o(26)
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};