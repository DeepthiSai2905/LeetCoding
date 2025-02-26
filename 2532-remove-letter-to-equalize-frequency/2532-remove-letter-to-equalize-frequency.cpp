class Solution {
public:
    bool equalFrequency(string word) {
        vector<int>freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            // check each removal
            if(freq[i]==0) continue;
            if(freq[i]>0) freq[i]--;
            int unique=-1;
            bool valid=true;
            for(int i=0;i<26;i++){
                if(freq[i]==0) continue;
                if(unique==-1){
                    unique=freq[i];
                }
                else{
                    if(unique!=freq[i]){
                        valid=false;
                        break;
                    }
                }
                
            }
            freq[i]++; // readd
            if(valid) return true;
        }
        return false;
    }
};