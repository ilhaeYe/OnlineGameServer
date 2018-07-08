//
//  CLog.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 8..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "CLog.hpp"

bool CLog::WriteLog(const char* data, ...)
{
    time_t now;
    char curDate[32] = {0,};
    char curFileName[128] = {0,};
    FILE* filePtr = nullptr;
    char debugLog[128] = {0,};
    
    va_list ap;
    char log[128] = {0,};
    
    va_start(ap, data);
    vsprintf(log, data, ap);
    va_end(ap);
    
    time(&now);
    const tm* t = localtime(&now);
    snprintf(curDate, 32, "%d-%d-%d %d:%d:%d",
             t->tm_year+1900,
             t->tm_mon+1,
             t->tm_mday,
             t->tm_hour,
             t->tm_min,
             t->tm_sec);
    
    snprintf(curFileName, 128, "LOG_%d-%d-%d.log",
             t->tm_year+1900,
             t->tm_mon+1,
             t->tm_mday);
    
    filePtr = fopen(curFileName, "a");
    if (!filePtr){
        return false;
    }
    
    fprintf(filePtr, "[%s] %s\n" ,curDate, log);
    snprintf(debugLog, 128, "[%s] %s\n", curDate, log);
    
    fflush(filePtr);
    fclose(filePtr);
    
    // OutputDebugString(debuglog);
    printf("%s", debugLog);
    
    return true;
}

void ExampleCLog()
{
    CLog::WriteLog("TEST LOG : DATA1(%d), DATA2(%d)", 10, 20);
}
