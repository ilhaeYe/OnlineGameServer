//
//  CLog.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CLog_hpp
#define CLog_hpp

class CLog
{
public:
    static bool WriteLog(const char* data, ...);
};

void ExampleCLog();

#endif /* CLog_hpp */
