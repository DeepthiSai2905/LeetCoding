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
            // we dont need to iterate over freq 
            if(skipFlag){
                currCount--; // skip one
                int rem=currCount%2;
                sum+=num*(currCount/2);
                currCount/=2;
                // now skipflag will be false
                skipFlag=false;
                if(rem==1) { 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }
            }
            else{ // dont skip
                sum+=num*(currCount/2);
                int rem=currCount%2;
                // now skipflag will be false
                if(rem==1) { 
                    sum+=num;
                    currCount--;
                    skipFlag=true;
                }

            }
            
        }
        return sum;
    }
};