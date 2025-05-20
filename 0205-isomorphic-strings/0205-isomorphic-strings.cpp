class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpST;
        unordered_map<char,char>mpTS;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c1=s[i], c2=t[i];

            // present and not equal
            if(mpST.find(c1)!=mpST.end()){
                if(mpST[c1]!=c2) return false;
            }
            else mpST[c1]=c2;
            if(mpTS.find(c2)!=mpTS.end()){
                if(mpTS[c2]!=c1) return false;
            }
            else mpTS[c2]=c1;
        }
        return true;
        
    }
};