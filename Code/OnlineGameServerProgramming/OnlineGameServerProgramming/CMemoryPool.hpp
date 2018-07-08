//
//  CMemoryPool.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 7..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CMemoryPool_hpp
#define CMemoryPool_hpp

template <class T, int ALLOC_BLOCK_SIZE = 50>
class CMemoryPool {
using UCHAR = unsigned char;
public:
    static void* operator new(std::size_t allocLength){
        assert(sizeof(T) == allocLength);
        assert(sizeof(T) >= sizeof(UCHAR*));
        
        if (!_ptr){
            allocBlock();
        }
        UCHAR* retPtr = _ptr;
        _ptr = *reinterpret_cast<UCHAR**>(retPtr);
        return retPtr;
    }
    static void operator delete(void* delPtr){
        *reinterpret_cast<UCHAR**>(delPtr) = _ptr;
        _ptr = static_cast<UCHAR*>(delPtr);
    }

private:
    static void allocBlock(){
        _ptr = new UCHAR[sizeof(T) * ALLOC_BLOCK_SIZE];
        UCHAR** cur = reinterpret_cast<UCHAR**>(_ptr);
        UCHAR* next = _ptr;
        for(int i=0; i<ALLOC_BLOCK_SIZE-1; ++i){
            next += sizeof(T);
            *cur = next;
            cur = reinterpret_cast<UCHAR**>(next);
        }
        
        *cur = nullptr;
    }
    
private:
    static UCHAR* _ptr;

};

template <class T, int ALLOC_BLOCK_SIZE>
UCHAR* CMemoryPool<T, ALLOC_BLOCK_SIZE>::_ptr;

class CData
{
private:
    BYTE a[1024];
    BYTE b[1024];
};

class CDataMP : public CMemoryPool<CDataMP>
{
private:
    BYTE a[1024];
    BYTE b[1024];
};

// example func
void ExampleCMemory();

#endif /* CMemoryPool_hpp */
