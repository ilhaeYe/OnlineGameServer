//
//  CCrypt.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "CCrypt.hpp"

const int C1 = 52845;
const int C2 = 22719;
const int KEY = 72957;

bool CCrypt::Encrypt(BYTE* src, BYTE* dest, DWORD length)
{
    int key = KEY;
    if (!src || !dest || length <= 0){
        return false;
    }
    
    for (int i=0; i<length; ++i){
        dest[i] = src[i] ^ key >> 8;
        key = (dest[i] + key) * C1 + C2;
    }
    
    return true;
}

bool CCrypt::Decrypt(BYTE* src, BYTE* dest, DWORD length)
{
    int key = KEY;
    BYTE preBlock;
    if (!src || !dest || length <= 0){
        return false;
    }
    
    for (int i=0; i<length; ++i){
        preBlock = src[i];
        dest[i] = src[i] ^ key >> 8;
        key = (preBlock + key) * C1 + C2;
    }
    
    return true;
}

void ExampleCrypt()
{
    BYTE src[4] = {0x00, 0x00, 0x01, 0x00};
    BYTE dest[4];
    
    printf("init src : %x %x %x %x\n", src[0], src[1], src[2], src[3]);
    CCrypt::Encrypt(src, dest, 4);
    printf("encrypt src : %x %x %x %x\n", dest[0], dest[1], dest[2], dest[3]);
    CCrypt::Decrypt(dest, src, 4);
    printf("decrypt src : %x %x %x %x\n", src[0], src[1], src[2], src[3]);
}
