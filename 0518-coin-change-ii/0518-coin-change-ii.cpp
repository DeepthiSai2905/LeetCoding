class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // // space optimisation 
        int n=coins.size();
        vector<unsigned long long>curr(amount+1);
        vector<unsigned long long>prev(amount+1,0);
        // take first coin and check for amount
        prev[0]=1;
        for(int i=0;i<n;i++){
            curr[0]=1;
            for(int j=coins[i];j<=amount;j++){
                curr[j]= prev[j] + curr[j-coins[i]];
            }
            prev=curr;
        }
        return prev[amount];  
    }
};