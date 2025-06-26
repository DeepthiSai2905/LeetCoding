class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first){ // distance same
               return a.second<b.second; // a has low priority, b on top - max heap
            }
            return a.first<b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        // k closest - maxheap
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp>pq; // dist,value
        for(int num:arr){ // nlogk
            pq.push({abs(x-num),num});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(),result.end()); // klogk
        return result;

    }
};