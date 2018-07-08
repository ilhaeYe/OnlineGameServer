//
//  CUser.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 7..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CUser_hpp
#define CUser_hpp

// account
class CUser
{
public:
    CUser();
    ~CUser();

public:
    void SetUserId(const char* userId, const char* password);
    void SetUserInfo(const char* name, const char* address, const int age);
    
protected:
    virtual void OnUpdateUserId() = 0;
    
private:
    char _userId[MAX_CHAR_SIZE];
    char _password[MAX_CHAR_SIZE];
    char _name[MAX_CHAR_SIZE];
    char _address[MAX_CHAR_SIZE];
    
    int _age;
    
};

// in game
class CGameUser : public CUser
{
public:
    CGameUser();
    ~CGameUser();
    
public:
    void SetGameInfo(const char* charName, int level);
    
private:
    virtual void OnUpdateUserId();
    
private:
    char _charName[MAX_CHAR_SIZE];
    
    int _level;
    
};

// in web
class CWebUser : public CUser
{
public:
    CWebUser();
    ~CWebUser();
    
public:
    void SetWebInfo(const char* boardName);
    
private:
    char _boardName[MAX_CHAR_SIZE];
    
};

#endif /* CUser_hpp */
