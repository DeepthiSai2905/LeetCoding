class MyQueue {
public:
  // pop heavy
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
       /* 
       1. shift elements of s1 to s2 
       2. pop top of s2
       3.  shift elements of s2 to s1 back to keep push in o(1)
       */
       while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       int poppedEle = s2.top(); s2.pop();
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       return poppedEle;
    }
    
    int peek() {
        while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
       }
       int topEle = s2.top();
       while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
       }
       return topEle;
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