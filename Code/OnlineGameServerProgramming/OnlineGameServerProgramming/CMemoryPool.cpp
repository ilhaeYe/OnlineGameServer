//
//  CMemoryPool.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 7..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "stdafx.pch"
#include "CMemoryPool.hpp"

void ExampleCMemory()
{
    int forCnt = 1000000;
    clock_t t = clock();
    for (int i= 0; i< forCnt; ++i){
        CData* pData = new CData();
        delete pData;
    }
    t = clock() - t;
    std::cout << "no use memory pool : " << ((double)t)/CLOCKS_PER_SEC << " sec" << std::endl;

    t = clock();
    for (int i= 0; i< forCnt; ++i){
        CDataMP* pData = new CDataMP();
        delete pData;
    }
    t = clock() - t;
    std::cout << "use memory pool : " << ((double)t)/CLOCKS_PER_SEC << " sec" << std::endl;
}
