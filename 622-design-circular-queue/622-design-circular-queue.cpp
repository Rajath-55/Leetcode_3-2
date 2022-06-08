class MyCircularQueue {
public:
    vector<int>queue;
    int rear;
    int numElements;
    int front;
    int k;
    
    MyCircularQueue(int k) {
        this->k = k;
        queue.resize(k);
        rear = 0;
        numElements = 0;
        front = 0;
    }
    
    bool enQueue(int value) {
        if(this->isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1)%k;
        numElements++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        numElements--;
        front = front +1;
        front%=k;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        if(rear - 1 < 0) return queue.back();
        return queue[rear - 1];
    }
    
    bool isEmpty() {
        return numElements == 0;
    }
    
    bool isFull() {
        return numElements == k;
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
 
 
 1 2 3 4
   
 
 */
