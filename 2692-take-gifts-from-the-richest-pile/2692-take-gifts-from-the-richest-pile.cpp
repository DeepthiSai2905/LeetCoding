class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int gift:gifts){
            pq.push(gift);
        }
        while(k--){
            int val = pq.top(); pq.pop();
            int sqrtVal = sqrt(val); pq.push(sqrtVal);
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top(); pq.pop();
        }
        return sum;
    }
};