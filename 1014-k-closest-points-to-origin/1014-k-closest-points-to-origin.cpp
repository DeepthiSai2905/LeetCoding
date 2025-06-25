class Solution {
public:
    struct comp{
        bool operator()(const vector<int>& pointA, const vector<int>& pointB){
            int distA = pointA[0]*pointA[0] + pointA[1]*pointA[1];
            int distB = pointB[0]*pointB[0] + pointB[1]*pointB[1];
            return distA<distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // no extra space
        sort(points.begin(),points.end(),comp());
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};