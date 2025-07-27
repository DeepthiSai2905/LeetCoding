class Solution {                                     
public:
    vector<int> partitionLabels(string s) {
        // max partitions
        vector<int>result;
        int n=s.length();
        unordered_map<int,int>mp;
        // track last occurence index of chars
        for(int i=0;i<n;i++) mp[s[i]]=i;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end=max(end,mp[s[i]]);
            if(i==end){
                result.push_back(end-start+1); // len of partition
                start=end+1;
            }
        }
        return result;


    }
};