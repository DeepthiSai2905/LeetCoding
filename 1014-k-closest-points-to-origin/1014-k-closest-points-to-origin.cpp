class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue <pair<int,int>> pq;

        for(int i=0;i<n;i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(pq.size() < k) {
                pq.push({dist, i});
            } else {
                if(pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist,i});
                }
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }

        return ans;
    }
};