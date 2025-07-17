class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX,maxi=INT_MIN;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
            mp[nums[i]]++;
        }
        int skipFlag=false; // if current element is computed, skip next
        // window from mini to maxi
        for(int num=mini;num<=maxi;num++){
            int currCount=mp[num];
            if(currCount<1) continue;
            while(currCount>0){
                if(skipFlag){ // skip
                    currCount--;
                    skipFlag=false;
                }else{ // dont skip 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }
                mp[num]=0;
            }
        }
        return sum;
    }
};