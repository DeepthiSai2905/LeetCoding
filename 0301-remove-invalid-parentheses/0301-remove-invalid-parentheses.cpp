class Solution {
public:
    bool isValid(string s){
        int count=0;
        for(char ch:s){
            if(ch=='(') count++;
            else if(ch==')') count--;
            if(count<0) return false;
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>result;
        unordered_set<string>vis;
        if(s.length()==0) return {};
        // dfs+backtracking or bfs
        queue<string>Q;
        Q.push(s);
        vis.insert(s);
        bool foundValid=false;
        while(!Q.empty()){
            int size=Q.size();
            for(int i=0;i<size;i++){
                string sub = Q.front(); Q.pop();
                if(isValid(sub)){
                    foundValid=true;
                    result.push_back(sub);
                    // vis.insert(sub);
                }
                // now apply for loop recursion for each substring if not valid
                else {
                    if(!foundValid){// then only create babies
                      for(int j=0;j<sub.length();j++){
                        if(sub[j]>='a' && sub[j]<='z') continue;
                        string child = sub.substr(0,j)+sub.substr(j+1);
                        // process only unvisited nodes
                        if(vis.count(child)==0){
                            Q.push(child);
                            vis.insert(child);
                        }
                      }
                    }
                }
            }
        }
        return result;

        
    }
};