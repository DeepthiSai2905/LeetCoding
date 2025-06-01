class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int sum=0,i=0,j=n-1;
        int count=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                count++; i++; j--;
            }
            else{
                count++; j--;
            }

        }
       
        return count;

    }
};