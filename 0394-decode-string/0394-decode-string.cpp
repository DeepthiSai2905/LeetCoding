class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        int curr_num=0;
        string curr_string="";
        for(char ch: s){
            if(isdigit(ch)){
                curr_num = curr_num*10+(ch-'0');
            }
            else if(ch=='['){
                st.push({curr_string, curr_num});
                curr_string="";
                curr_num=0;
            }
            else if(ch==']'){
                string prev_string=st.top().first;
                int num=st.top().second;

                st.pop();
                string curr=curr_string;
                while(num>1){
                    curr_string += curr;
                    num--;
                }
                curr_string = prev_string+curr_string;
            }
            else{
                curr_string+=ch;
            }
        }
        return curr_string;
    }
};