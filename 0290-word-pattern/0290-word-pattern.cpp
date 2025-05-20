class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mpPS;
        unordered_map<string,char>mpSP;

        vector<string>words;
        string word;
        
        istringstream iss(s);
        while (iss >> word) words.push_back(word);

        int patLen = pattern.length();
        if(words.size()!=patLen) return false;

        for(int i=0;i<patLen;i++){
            char ch=pattern[i];
            string word=words[i];
            
            if(mpPS.count(ch)){ // present
               if(mpPS[ch]!=word) return false;
            }
            else mpPS[ch]=word;

            if(mpSP.count(word)){ // present
               if(mpSP[word]!=ch) return false;
            }
            else mpSP[word]=ch;
        }
        return true;
    }
};