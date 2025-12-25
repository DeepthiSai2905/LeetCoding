class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        string result;
        string word="";
        while(i<n){
            if(s[i]==' '){
                i++;
            }
            else{
                // build word
                while(i<n && s[i]!=' '){
                    word+=s[i++];
                }
                reverse(word.begin(),word.end());
                if(!result.empty()) result+=" ";
                result+=word;
                word.clear();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};