class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp;
        vector<string>res;
        int minIndexSum=INT_MAX;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){ // present
               int indexSum=i+mp[list2[i]];
               if(indexSum < minIndexSum){
                  res = {list2[i]};
                  minIndexSum=indexSum;
               }else if(indexSum == minIndexSum){
                 res.push_back(list2[i]);
               }
               
            }
        }
        return res;


    }
};