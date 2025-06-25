class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s) mp[ch]++;

        priority_queue<pair<int,char>>pq;

        string result;
        for(auto itr:mp){ // O(n)
            pq.push({itr.second,itr.first});
        }
        while(!pq.empty()){ // o(nlogn)
            auto it = pq.top(); 
            pq.pop();
            int freq  = it.first;
            char ch = it.second;
            while(freq--){
                result+=ch;
            }
        }
        return result;

    }
};