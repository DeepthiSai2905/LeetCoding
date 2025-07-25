class Solution {
public:
    bool match(char c1,char c2){
        if(c1=='{' && c2=='}') return true;
        if(c1=='[' && c2==']') return true;
        if(c1=='(' && c2==')') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && match(st.top(),s[i])){
                    st.pop();
                }
                else return false;
            }
        }
        return(st.empty());
    }
};