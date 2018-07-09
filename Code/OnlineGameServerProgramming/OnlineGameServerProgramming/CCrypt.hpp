//
//  CCrypt.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CCrypt_hpp
#define CCrypt_hpp

class CCrypt
{
public:
    static bool Encrypt(BYTE* src, BYTE* dest, DWORD length);
    static bool Decrypt(BYTE* src, BYTE* dest, DWORD length);
    
};

void ExampleCrypt();

#endif /* CCrypt_hpp */
