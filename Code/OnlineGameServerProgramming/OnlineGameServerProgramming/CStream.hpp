//
//  CStream.hpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 5..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#ifndef CStream_hpp
#define CStream_hpp

class CStream
{
public:
    CStream();
    ~CStream();

public:
    bool SetBuffer(BYTE* buffer);
    DWORD GetLength();

    // read
    bool ReadInt32(int32_t* data);
    bool ReadInt64(int64_t* data);
    bool ReadDword(DWORD* data);
    bool ReadByte(BYTE* data);
    bool ReadBytes(BYTE* data, DWORD length);
    bool ReadFloat(float* data);
    bool ReadShort(short* data);
    bool ReadUShort(unsigned short* data);
    bool ReadBool(bool* data);
    
    //write
    bool WriteInt32(int32_t data);
    bool WriteInt64(int64_t data);
    bool WriteDword(DWORD data);
    bool WriteByte(BYTE data);
    bool WriteBytes(BYTE* data, DWORD length);
    bool WriteFloat(float data);
    bool WriteShort(short data);
    bool WriteUShort(unsigned short data);
    bool WriteBool(bool data);

private:
    BYTE* _buffer;
    DWORD _length;

};

// smart pointer
// code for study
class CStreamSP
{
public:
    CStreamSP();
    ~CStreamSP();
    
public:
    CStream* operator->();
    CStream operator*();
    
private:
    CStream* _ptr;
    
};

// example func
void ExampleCStream();

#endif /* CStream_hpp */
