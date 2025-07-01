class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
    
    int myAtoi(string s) {
        int n=s.length();
        bool neg=false;
        int i=0;

        // 1. remove leading whitespaces
        while(i<n && s[i]==' ') i++;

       // check for + or - sign
        if(i<n && (s[i]=='-' || s[i]=='+')){
            neg=(s[i]=='-');
            i=i+1;
        }

        // it should not have a
        long res=0;


        // stop reading when you reach non-digits
        while(i<n && isDigit(s[i])){

            // conversion
            int val = (s[i]-'0');
            // INT_MAX = 2^31-1, INT_MIN = -2^31
            // if(res>INT_MAX || res<INT_MIN){
            //     overflow=true;
            // }

            //rounding
            if (res > (INT_MAX - val) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }
            res=res*10+val;
            i++;
        }
        // if(overflow) neg ? INT_MIN : INT_MAX;
        return neg ? res*-1 : res;
        
    }
};