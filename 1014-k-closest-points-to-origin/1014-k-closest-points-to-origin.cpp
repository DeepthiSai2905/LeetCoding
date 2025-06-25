class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>result;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist = x*x+y*y;
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            int index = pq.top().second;
            result.push_back(points[index]);
            pq.pop();
        }
        return result;
    }
};