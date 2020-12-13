#include <iostream>
#include <vector>


class MyCircularQueue {
private:
    int head;
    vector<int> data;
    int tail;
public:
    MyCircularQueue(int k) {
        data = vector<int>(k,0);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        else{
            if(tail == data.size()){
                tail = 0;
                data.push_back(value);
                return true;
            }
            data.push_back(value);
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            if(head == data.size()){
            head = 0;
            return true;
            }
            head++;
            return true;
        }
    }
    
    int Front() {
        return data[head];
    }
    
    int Rear() {
        return data[tail];
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        if(tail == data.size()){
            return head == 0;
        }
        return head == tail-1;
    }
};
