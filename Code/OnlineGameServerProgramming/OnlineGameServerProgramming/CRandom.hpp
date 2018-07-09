//
//  CRandom.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 10..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CRandom_hpp
#define CRandom_hpp

class CRandom
{
public:
    CRandom();
    virtual ~CRandom();
    
public:
    bool Init(uint seed);
    
    int Rand();
    int SimpleRandom();
    int ComplexRandom();
    
private:
    uint _seed;

};

void ExampleCRandom();

#endif /* CRandom_hpp */
