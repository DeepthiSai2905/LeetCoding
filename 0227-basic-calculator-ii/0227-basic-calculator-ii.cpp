
class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        int n=s.length();
        if(n==0) return 0;
        // trim start and end spaces in string

        stack<int>st;
        int currNum=0;
        char lastSign='+';
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isDigit(ch)){
                currNum=currNum*10+(ch-'0');
            }
            if((!isDigit(ch) && ch!=' ') || i==n-1){
                int value;
                if(lastSign=='+') value = currNum;
                else if(lastSign=='-') value = currNum*-1;
                else if(lastSign=='*'){
                    value = currNum*st.top();
                    st.pop();
                }else if(lastSign=='/'){
                    value = st.top()/currNum;
                    st.pop();
                }
                st.push(value);
                currNum=0;
                lastSign=ch;
            }
        }
        int result=0;
        while(!st.empty()){
            result+=st.top(); st.pop();
        }
       return result; 
    }
};