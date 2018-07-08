//
//  CCircularQueue.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "CCircularQueue.hpp"

void ExampleCCircular(){
    typedef struct _QUEUE_DATA{
        int iData1;
        BYTE aData2[100];
    }QUEUE_DATA;
    
    CCircularQueue<QUEUE_DATA> queue;
    queue.Begin();
    
    QUEUE_DATA pushData;
    pushData.iData1 = 10;
    ZeroMemory(pushData.aData2, sizeof(pushData.aData2));
    
    queue.Push(pushData);
    
    QUEUE_DATA popData;
    queue.Pop(popData);
    
}
