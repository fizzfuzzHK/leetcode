#include <iostream>
#include <vector>

class MyCircularQueue {
    std::vector<int> data;
    int head;
    int tail;
    // current size
    int cs;
    // max size
    int ms;

public:
    MyCircularQueue(int k) {
        data = std::vector<int>(k,0);
        head = 0;
        tail = k-1;
        cs = 0;
        ms = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else{
            tail = (tail+1)%ms;
            data[tail] = value;
            cs++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            head = (head+1)%ms;
            cs--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
         if(isEmpty()){
            return -1;
         }
        return data[tail];
    }
    
    bool isEmpty() {
        return (cs == 0);
    }
    
    bool isFull() {
        return (cs == ms);
    }
};

// int main(void){
    // MyCircularQueue q(5);
    // std::cout << q.Front() << std::endl;
    // q.enQueue(5);
    // q.enQueue(3);
    // if (!q.isEmpty()) {
    //     std::cout << q.Front() << std::endl;
    // }
// }
