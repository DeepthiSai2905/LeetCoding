class Solution {
public:
    bool checkforIsomorphic(string s, string t){
        unordered_map<char,char>mpST;
        unordered_set<char>mappedChars;
        for(int i=0;i<s.length();i++){
            if(mpST.count(s[i])){
                if(mpST[s[i]]!=t[i]) return false;
            }
            else {
                if(mappedChars.find(t[i])!=mappedChars.end()) return false;
                mpST[s[i]]=t[i];
                mappedChars.insert(t[i]);
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for(string s:words){
            if(checkforIsomorphic(s,pattern)){
                res.push_back(s);
            }
        }   
        return res;
    }
};