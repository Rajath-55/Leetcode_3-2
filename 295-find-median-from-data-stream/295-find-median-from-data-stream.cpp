class MedianFinder {
public:
    priority_queue<double>lower;
    priority_queue<double, vector<double>, greater<double>>upper;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.empty() or num < lower.top()){
            lower.push(num);
        }else{
            upper.push(num);
        }
        if(lower.size() > upper.size() + 1){
            upper.push(lower.top());
            lower.pop();
        }
        if(upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() != upper.size()) return lower.top();
        return (double) (lower.top() + upper.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */