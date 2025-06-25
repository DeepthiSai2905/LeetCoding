class MedianFinder {
public:

    priority_queue<int>leftmaxHp;
    priority_queue<int, vector<int>, greater<int>>rightminHp;

    MedianFinder() {
    }
    
    void addNum(int num) {
        // left max heap [1,2,3] right min heap [4,5,6] 
        // make sure maxhp small heap elements <= minHp large heap elements

        if(leftmaxHp.empty() || leftmaxHp.top()>=num) {
            leftmaxHp.push(num);
        }
        else{
            rightminHp.push(num);
        }

        // balance heaps - i want to keep maxheap 1 extra in case of odd
        if (leftmaxHp.size() > rightminHp.size() + 1) {
            rightminHp.push(leftmaxHp.top());
            leftmaxHp.pop();
        }
        else if(rightminHp.size()>leftmaxHp.size()){
            int mini=rightminHp.top(); rightminHp.pop();
            leftmaxHp.push(mini);
        }

    }
    
    double findMedian() {
        if(rightminHp.size()==leftmaxHp.size()){
            return (rightminHp.top()+leftmaxHp.top())/ 2.0;
        }
        return leftmaxHp.top();
    }
     
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */