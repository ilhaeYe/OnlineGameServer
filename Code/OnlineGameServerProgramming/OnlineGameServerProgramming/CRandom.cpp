//
//  CRandom.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 10..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "CRandom.hpp"
CRandom::CRandom()
{
    
}

CRandom::~CRandom()
{
    
}

bool CRandom::Init(uint seed)
{
    _seed = seed;
    
    return true;
}

int CRandom::Rand()
{
    return ( ((_seed = _seed * 214013L + 2531011L) >> 16) & 0x7FFF );
}

int CRandom::SimpleRandom()
{
    return ( ((_seed = _seed + 2531011L) >> 3) & 0x7FFF );
}

int CRandom::ComplexRandom()
{
    uint next = _seed;
    int result;
    
    next *= 1103515245;
    next += 12345;
    result = (uint) (next / 65536) % 2048;
    
    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (uint) (next / 65536) % 1024;
    
    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (uint) (next / 65536) % 1024;

    _seed = next;
    return result;
}

void ExampleCRandom()
{
    CRandom cr;
    cr.Init(500);
    std::cout << cr.Rand() << std::endl;
    std::cout << cr.SimpleRandom() << std::endl;
    std::cout << cr.ComplexRandom() << std::endl;

}

