class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>Q;
        Q.push({beginWord,1});
        while(!Q.empty()){
            string curr = Q.front().first;
            int steps = Q.front().second;
            Q.pop();
            
            if(curr==endWord) return steps;

            for(int i=0;i<curr.length();i++){
                char original = curr[i];
                for(char ch='a';ch<='z';ch++){
                    curr[i]=ch;
                    if(s.find(curr)!=s.end()){ // exists
                        s.erase(curr);
                        Q.push({curr, steps+1});
                    }
                }
                curr[i]=original;
            }
        }
        return 0;
    }
};