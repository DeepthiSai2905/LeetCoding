class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> &v = store[key];
        int i=0,j=v.size()-1;
        string res="";
        // find value which is just arr[index]<= x
        while(i<=j){
            int mid=i+(j-i)/2;
            if(v[mid].first <= timestamp){
                res=v[mid].second;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return res;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */