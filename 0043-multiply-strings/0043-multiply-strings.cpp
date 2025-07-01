class Solution {
public:
    string multiply(string num1, string num2) { 
        if(num1=="0" || num2=="0") return "0"; 
        int n = num2.length();
        int m=num1.length();
        vector<int> res(n + m, 0);
        for(int i=n-1;i>=0;i--){ // o(n)
            // process num1
            for(int j=m-1;j>=0;j--){
                int prod=(num1[j]-'0')*(num2[i]-'0');
                int sum = res[i + j + 1] + prod;
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10; // carry
            }
        }
        // Convert res vector to string
        string result;
        int k=res.size();
        int i=0;
        while(i<k && res[i]==0) i++;
        while(i<k) {
            result += to_string(res[i++]);
        }
        return result.empty() ? "0" : result;
    }
};