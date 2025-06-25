class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        priority_queue<pair<int,int>>pq;
        vector<string>result(n);
        for(int i=0;i<score.size();i++){ // nlogn
            pq.push({score[i],i});
        }
        int count = 1;
        while(!pq.empty()){ // n times pop - nlogn 
            int idx = pq.top().second;
            if(count<4) result[idx]=medals[count-1];
            else result[idx]=to_string(count);
            count++;
            pq.pop();
        }
        return result;
    }
};