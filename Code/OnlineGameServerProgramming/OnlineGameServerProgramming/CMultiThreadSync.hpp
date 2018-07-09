//
//  CMultiThreadSync.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 9..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CMultiThreadSync_hpp
#define CMultiThreadSync_hpp

class CCriticalSection
{
public:
    CCriticalSection()
    {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&_mutex, &attr);

    }
    ~CCriticalSection() { pthread_mutex_destroy(&_mutex); }

public:
    inline void Enter() { pthread_mutex_lock(&_mutex); }
    inline void Leave() { pthread_mutex_unlock(&_mutex); }


private:
    pthread_mutex_t _mutex;

};

template <class T>
class CMultiThreadSync
{
    friend class CThreadSync;
public:
    class CThreadSync
    {
    public:
        CThreadSync() { T::_sync.Enter(); }
        ~CThreadSync() { T::_sync.Leave(); }
    };

private:
    static CCriticalSection _sync;

};

template<class T>
CCriticalSection CMultiThreadSync<T>::_sync;

#endif /* CMultiThreadSync_hpp */
