class MyCircularQueue {
public:
    deque<int>q;
    int cur_size;
    int max_size;
    MyCircularQueue(int k) {
        max_size = k;
        cur_size = 0;
    }
    
    bool enQueue(int value) {
        if(cur_size < max_size){
            q.push_back(value);
            cur_size ++;
            return true;
        }
        
        return false;
    }
    
    bool deQueue() {
        if(cur_size != 0)
        {
            q.pop_front();
            cur_size --;
            return true;
        }
        
        return false;
        
        
    }
    
    int Front() {
        if(cur_size != 0)
            return q.front();
        return -1;
    }
    
    int Rear() {
        if(cur_size != 0)
        return q.back();
        return -1;
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */