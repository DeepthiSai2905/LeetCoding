
class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        int n = s.length();
        int result = 0;
        int currNum = 0;
        int lastNum = 0;
        char sign = '+'; // Start with '+' so first num gets added to result

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            if (isDigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }

            // If not digit or last char: process operator
            if ((!isDigit(ch) && ch != ' ') || i == n - 1) {
                if (sign == '+') {
                    result += lastNum;
                    lastNum = currNum;
                } else if (sign == '-') {
                    result += lastNum;
                    lastNum = -currNum;
                } else if (sign == '*') {
                    lastNum = lastNum * currNum;
                } else if (sign == '/') {
                    lastNum = lastNum / currNum;
                }
                sign = ch;
                currNum = 0;
            }
        }

        result += lastNum; // Add the last evaluated number
        return result;
    }
};