class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_set<char>s;
        for(char ch:jewels) s.insert(ch);
        for(char ch:stones){
            if(s.find(ch)!=s.end()){
                count++;
            }
        } 
        return count;
    }
};