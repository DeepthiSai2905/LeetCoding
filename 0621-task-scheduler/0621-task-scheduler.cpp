class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<int,int>mp;
        int maxFreq=0, maxNum=0; // maxNum is total tasks with highest freq
        for(char ch:tasks){
            mp[ch]++;
            maxFreq=max(maxFreq,mp[ch]);
        }
        for(auto x:mp) {
            if(maxFreq==x.second){
                maxNum++;
            }
        }
        // calculate partitions, pending, available, idle
        int partitions = maxFreq-1;
        int available = partitions * (n-(maxNum-1));
        int pending = len - (maxFreq*maxNum);
        int idle = max(0, available-pending);
        return len+idle;
    }
};