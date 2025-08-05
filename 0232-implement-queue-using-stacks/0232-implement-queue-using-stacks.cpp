class MyQueue {
public:
  
    stack<int>s1;
    stack<int>s2;
    // use it as a team effeciently
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() { // how to make pop efficient
       /* 
        1. move elements from s1 to s2
        2. pop top of s2
        3. move back all elements from s2 to s1(why ???) - optimise try solving without moving them back
       idea is to consider s2 top as front and s1 top as end of queue
       */
       int poppedEle = peek();
       s2.pop();
       return poppedEle;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top()); s1.pop();
            }
        }
        if(s2.empty()) return -1;
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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