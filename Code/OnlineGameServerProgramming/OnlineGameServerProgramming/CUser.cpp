//
//  CUser.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 7..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "stdafx.pch"
#include "CUser.hpp"

// CUser ----------------------------
CUser::CUser() : _age(0)
{
    ZeroMemory(_userId, sizeof(char) * MAX_CHAR_SIZE);
    ZeroMemory(_password, sizeof(char) * MAX_CHAR_SIZE);
    ZeroMemory(_name, sizeof(char) * MAX_CHAR_SIZE);
    ZeroMemory(_address, sizeof(char) * MAX_CHAR_SIZE);
}
CUser::~CUser()
{
    
}

void CUser::SetUserId(const char* userId, const char* password)
{
    if(!userId || !password){
        return;
    }
    
    strncpy(_userId, userId, MAX_CHAR_SIZE);
    strncpy(_password, password, MAX_CHAR_SIZE);

    // call virtual func
    OnUpdateUserId();
}
void CUser::SetUserInfo(const char* name, const char* address, const int age)
{
    if(!name || !address){
        return;
    }
    
    strncpy(_name, name, MAX_CHAR_SIZE);
    strncpy(_address, address, MAX_CHAR_SIZE);
    _age = age;
    
}
// CUser ----------------------------

// CGameUser ----------------------------
CGameUser::CGameUser() : _level(0)
{
    ZeroMemory(_charName, MAX_CHAR_SIZE);
}

CGameUser::~CGameUser()
{
    
}

void CGameUser::SetGameInfo(const char* charName, int level)
{
    if (!charName){
        return;
    }
    
    strncpy(_charName, charName, MAX_CHAR_SIZE);
    _level = level;
}

void CGameUser::OnUpdateUserId()
{
    std::cout << "Update UserId" << std::endl;
}

// CGameUser ----------------------------

// CWebUser -----------------------------
CWebUser::CWebUser()
{
    ZeroMemory(_boardName, MAX_CHAR_SIZE);

}

CWebUser::~CWebUser()
{
    
}
    
void CWebUser::SetWebInfo(const char* boardName)
{
    if(boardName){
        return;
    }
    
    strncpy(_boardName, boardName, MAX_CHAR_SIZE);
}
// CWebUser -----------------------------
