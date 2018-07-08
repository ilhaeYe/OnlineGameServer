//
//  CCircularQueue.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CCircularQueue_hpp
#define CCircularQueue_hpp

template<class T>
class CCircularQueue
{
#define MAX_QUEUE_SIZE 1024
public:
    CCircularQueue(){
        ZeroMemory(_queue, sizeof(_queue));
        _head = _tail = 0;
    }
    ~CCircularQueue(){};
    
public:
    bool Begin(){
        ZeroMemory(_queue, sizeof(_queue));
        _head = _tail = 0;
        
        return true;
    }
    
    bool End() {
        return true;
    }
    
    bool Push(T data){
        DWORD tempTail = (_tail + 1) % MAX_QUEUE_SIZE;
        if (tempTail == _head){ // full
            return false;
        }
        
        CopyMemory(&_queue[tempTail], &data, sizeof(T));
        _tail = tempTail;
        
        return true;
    }
    
    bool Pop(T& data){
        if(_head == _tail){
            return false;
        }
        
        DWORD tempHead = (_head + 1) % MAX_QUEUE_SIZE;
        CopyMemory(&data, &_queue[tempHead], sizeof(T));
        _head = tempHead;
        
        return true;
    }
    
    bool IsEmpty(){
        return (_head == _tail);
    }
    
private:
    T _queue[MAX_QUEUE_SIZE];
    DWORD _head;
    DWORD _tail;
    
};

void ExampleCCircular();

#endif /* CCircularQueue_hpp */
