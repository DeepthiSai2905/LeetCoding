class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        vector<int>result;
        if (n < m) return result;
        // optimal 
        unordered_map<int,int>mp; // p string map
        for(char ch:p){
            mp[ch]++;
        }
        int matchCount=0;
        for(int i=0;i<n;i++){

            // incoming processing
            char in=s[i];
            if(mp.find(in)!=mp.end()){
                mp[in]--;
                if(mp[in]==0){ // unique match coming into window
                 matchCount++;
                }
            }
            // outgoing possible only from mth
            if(i>=m){
                char out=s[i-m];
                if(mp.find(out)!=mp.end()){
                    mp[out]++; // would have been a match in prev window
                    if(mp[out]==1){ // unique match going out of window
                      matchCount--;

                    }
                }
            }
            if(matchCount==mp.size()){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};