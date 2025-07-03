class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        int n=s.length();
        stack<int>st;
        char lastSign='+';
        int num=0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isDigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='('){ // process sign before (
               if(lastSign=='+') st.push(1);
               else if(lastSign=='-') st.push(-1);
              /* else if(lastSign=='*') st.push(2);
                 else st.push(-2);
              */
               st.push(INT_MAX); // to identify '(' to evaluate exp from ')'
               num=0; lastSign='+';
            }
            else if(ch==')'){
                // unwrap stack upto ( - u find INT_MAX
                // put last element first
                if(lastSign=='+') st.push(num);
               else if(lastSign=='-') st.push(-num);
              /* else if(lastSign=='*') {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop()
                st.push(last*num);
              }
               else {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop()
                st.push(last/num);
               }
               */

               // unwrap stack upto ( - u find INT_MAX
               int interRes=0;
               while(st.top()!=INT_MAX){
                 interRes+=st.top(); st.pop();
               }// reached ( in stack
               st.pop(); // pop INT_MAX ( first
               int popedEle = st.top(); // last sign before (
               st.pop();
               if(popedEle==1 || popedEle==-1) interRes*=popedEle;
              /* else if(popedEle==2) // multiply logic
                 else if(popedEle==-2) // divide logic
              */
              st.push(interRes);
              num=0;
              lastSign='+'; // we processed all +,-,*,/ so make it '+'
            }
            else if((!isDigit(ch) && ch!=' ') ){ // operator
               // process last sign first before updating lastSign
               if(lastSign=='+') st.push(num);
               else if(lastSign=='-') st.push(-num);
              /* else if(lastSign=='*') {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop()
                st.push(last*num);
              }
               else {
                // pop 1 more element, mul it to num & push into stack
                int last = st.top(); st.pop()
                st.push(last/num);
               }
               */
               num=0;
               lastSign=ch;
            }
            
        }

        int result=0;
        // this is not handled, though num is calculated operator calculation is not done
        if(s[n-1]!=')'){
            if(lastSign=='+') st.push(num);
            else if(lastSign=='-') st.push(-num);
        }
        while(!st.empty()){
            result+=st.top(); st.pop();
        }
        return result;
    }
};