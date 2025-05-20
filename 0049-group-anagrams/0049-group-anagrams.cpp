class Solution {
public:
    string decodeString(string s){
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        string res;
        for(char c='a';c<='z';c++){
           if(v[c-'a']!=0){
            res+=c;
            res+=to_string(v[c-'a']);
           } 
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>mp;
        for(string s:strs){
            string decode=decodeString(s);
            mp[decode].push_back(s);
        }
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};