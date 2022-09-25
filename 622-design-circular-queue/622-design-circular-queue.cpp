class MyCircularQueue {
public:
    int *arr;
    int max_size;
    int cur_size;
    int front;
    int back;
    MyCircularQueue(int k) {
        arr = new int[k];
        max_size = k;
        cur_size = 0;
        front = 0;
        back = -1;
    }
    
    bool enQueue(int value) {
        if(cur_size==max_size) return false;
        back = (back+1)%max_size;
        arr[back] = value;
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if(cur_size==0) return false;
        front = (front+1)%max_size;
        cur_size--;
        return true;
    }
    
    int Front() {
        if(cur_size==0) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(cur_size==0) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        if(cur_size==0) return true;
        return false;
    }
    
    bool isFull() {
        if(cur_size==max_size) return true;
        return false;
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