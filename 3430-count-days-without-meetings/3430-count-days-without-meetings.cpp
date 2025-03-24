class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int ans=0;

        sort(meetings.begin(),meetings.end());
        int mergeStart=meetings[0][0];
        int mergeEnd=meetings[0][1];
        for(int i=1;i<n;i++){
            if(meetings[i][0]>mergeEnd){
                ans+=(meetings[i][0]-mergeEnd-1);
                mergeStart=meetings[i][0];
                mergeEnd=meetings[i][1];
            }
            else{
                mergeEnd = max(mergeEnd, meetings[i][1]);
            }
        }
        if(meetings[0][0]>1){
            ans+=(meetings[0][0]-1);
        }
        if(mergeEnd<days){
            ans+=(days - mergeEnd);
        }
        return ans;
    }
};