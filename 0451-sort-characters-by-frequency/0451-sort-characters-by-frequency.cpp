class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s) mp[ch]++;

        int n=s.length();
        string result;
        vector<vector<char>>v(n+1);
        for(auto itr:mp){ // O(n)
            v[itr.second].push_back(itr.first);
        }
        for(int i=n;i>0;i--){ // o(n)
            for(auto ch: v[i]){
                for(int count=0;count<i;count++){
                    result+=ch;
                }
            }
        }
        return result;

    }
};