class Solution {
public:
    vector<string> units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> suffix = {"","Thousand", "Million", "Billion"};
    
    string trim(const string& str) {
    int start = str.find_first_not_of(' ');
    int end = str.find_last_not_of(' ');
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

    string decodeTriplet(int curr){
        // 543
        if(curr>=100){
            return units[curr/100] + " Hundred " + decodeTriplet(curr%100);
        }
        else if(curr>=20){
            return tens[curr/10] + " " + units[curr%10];
        }
        else{
            return units[curr];
        }
        return "";
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        string result;
        int i=0;

        // chunk of triplets
        while(num>0){
            if(num%1000!=0){
                string triplet = trim(decodeTriplet(num%1000));
                // result = triplet + " " + suffix[i] +" " + result; 
                if (!triplet.empty()) {
                    result = triplet + (suffix[i].empty() ? "" : " " + suffix[i]) + (result.empty() ? "" : " " + result);
                }
            }
            i++;
            num=num/1000;
        }
        // trim ending spaces
        return trim(result);
    
    }
};