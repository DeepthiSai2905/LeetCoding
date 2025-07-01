class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>mp;
        for(string word:strs){
            vector<int> count(26, 0);

            for (char c : word) {
                count[c - 'a']++;
            }

            string decode;
            for (int i = 0; i < 26; ++i) {
                decode += '#' + to_string(count[i]); // Use '#' as delimiter
            }
            mp[decode].push_back(word);
        }
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};