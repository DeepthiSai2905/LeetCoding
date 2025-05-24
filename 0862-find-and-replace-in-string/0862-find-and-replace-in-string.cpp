class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=s.length();
        int i=0;
        string res="";
        map<int,pair<string,string>>hash;
        
        int indsize=indices.size();
        for(int i=0;i<indsize;i++){
            int ind=indices[i];
            string src=sources[i];
            if(s.substr(ind,src.length())==src)
            hash[ind]={src,targets[i]};
        }
        while(i<n){
            if(hash.find(i)!=hash.end()){
                string src = hash[i].first;
                int sublen=src.length();
                res+=hash[i].second;
                i+=sublen;
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};