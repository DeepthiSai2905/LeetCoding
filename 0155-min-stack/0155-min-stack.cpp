class MinStack {
public:
   /*
    newVal < val --- 1
    val < minEle
    val+val<minEle+val
    2*val - minEle < val -- 2
    comparing 1&2 => newVal = 2*val-minEle
   */
    stack<long long>s;
    long long minEle = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val); minEle=val;
            return ;
        }
        if(val<minEle){ // update mini but before that push newvalue
           long long newVal = 2LL*val-minEle;
           s.push(newVal);
           minEle = val;
        }
        else{
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return ;
        long long topEle = s.top(); s.pop();
        if(topEle < minEle){ // modified value found
           minEle = 2*minEle - topEle;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        long long topEle = s.top();
        if(topEle < minEle){ // modified value found
           return minEle;
        }
        return (int)topEle;
    }
    
    int getMin() {
       if(s.empty()) return -1;
       return (int)minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */