class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // n is diff from logs length
        vector<int>result(n,0);
        stack<int>st;
        int currtimestamp=0,prevtimestamp=0;
        for(string log: logs){
            istringstream stream(log);
            vector<string>parts;
            string part;
            while (std::getline(stream, part, ':')) {
                parts.push_back(part);
            }
            int funcId = stoi(parts[0]);
            string type = parts[1];
            currtimestamp = stoi(parts[2]);
            if(type == "start"){
                // prev task paused
                if(!st.empty()){
                    result[st.top()]+=(currtimestamp - prevtimestamp);
                }
                prevtimestamp=currtimestamp;
                st.push(funcId);
            }
            else{ // resolve
               result[funcId]+=(currtimestamp - prevtimestamp +1);
               st.pop();
               prevtimestamp=currtimestamp+1;
            }
        }
        return result;

    }
};