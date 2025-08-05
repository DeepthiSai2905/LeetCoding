class MyQueue {
public:
  // push heavy, pop top light
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        /* 
       1. shift elements of s1 to s2 
       2. push element to s1
       3. shift elements of s2 to s1 back to keep pop in o(1)
       */
       while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       s1.push(x);
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       
    }
    
    int pop() {
       if(s1.empty()) return -1;
       int poppedEle = s1.top(); s1.pop();
       return poppedEle;
    }
    
    int peek() {
       if(s1.empty()) return -1;
       return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */