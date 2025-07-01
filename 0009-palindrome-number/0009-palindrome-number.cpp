class Solution {
public:
    bool isPalindrome(int num) {
        if(num<0) return false;
        int x=num;
        long rev=0;
        while(x>0){
            int rem=x%10;
            rev=rev*10+rem;
            x/=10;
        }
        return num==rev;
    }
};