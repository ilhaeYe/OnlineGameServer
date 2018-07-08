//
//  CStream.cpp
//  OnlineGameServerProgramming
//
//  Created by 예일해 on 2018. 7. 5..
//  Copyright © 2018년 RomanceDuck. All rights reserved.
//

#include "stdafx.pch"
#include "CStream.hpp"

// CStream  -------------------------------
CStream::CStream() : _buffer(nullptr), _length(0){

}

CStream::~CStream(){
}


bool CStream::SetBuffer(BYTE* buffer){
    if (!buffer){
        return false;
    }

    _buffer = buffer;
    return true;
}

DWORD CStream::GetLength(){
    return _length;
}

// read
bool CStream::ReadInt32(int32_t* data){
    CopyMemory(data, _buffer + _length, sizeof(int32_t));
    _length += sizeof(int32_t);
    return true;
}
bool CStream::ReadInt64(int64_t* data){
    CopyMemory(data, _buffer + _length, sizeof(int64_t));
    _length += sizeof(int64_t);
    return true;
}
bool CStream::ReadDword(DWORD* data){
    CopyMemory(data, _buffer + _length, sizeof(DWORD));
    _length += sizeof(DWORD);
    return true;
}
bool CStream::ReadByte(BYTE* data){
    CopyMemory(data, _buffer + _length, sizeof(BYTE));
    _length += sizeof(BYTE);
    return true;
}
bool CStream::ReadBytes(BYTE* data, DWORD length){
    CopyMemory(data, _buffer + _length, sizeof(BYTE) * length);
    _length += sizeof(BYTE) * length;
    return true;
}
bool CStream::ReadFloat(float* data){
    CopyMemory(data, _buffer + _length, sizeof(float));
    _length += sizeof(float);
    return true;
}
bool CStream::ReadShort(short* data){
    CopyMemory(data, _buffer + _length, sizeof(short));
    _length += sizeof(short);
    return true;
}
bool CStream::ReadUShort(unsigned short* data){
    CopyMemory(data, _buffer + _length, sizeof(unsigned short));
    _length += sizeof(unsigned short);
    return true;
}
bool CStream::ReadBool(bool* data){
    CopyMemory(data, _buffer + _length, sizeof(bool));
    _length += sizeof(bool);
    return true;
}

//write
bool CStream::WriteInt32(int32_t data){
    CopyMemory(_buffer + _length, &data, sizeof(int32_t));
    _length += sizeof(int32_t);
    return true;
}
bool CStream::WriteInt64(int64_t data){
    CopyMemory(_buffer + _length, &data, sizeof(int64_t));
    _length += sizeof(int64_t);
    return true;
}
bool CStream::WriteDword(DWORD data){
    CopyMemory(_buffer + _length, &data, sizeof(DWORD));
    _length += sizeof(DWORD);
    return true;
}
bool CStream::WriteByte(BYTE data){
    CopyMemory(_buffer + _length, &data, sizeof(BYTE));
    _length += sizeof(BYTE);
    return true;
}
bool CStream::WriteBytes(BYTE* data, DWORD length){
    CopyMemory(_buffer + _length, &data, sizeof(BYTE) * length);
    _length += sizeof(BYTE) * length;
    return true;
}
bool CStream::WriteFloat(float data){
    CopyMemory(_buffer + _length, &data, sizeof(float));
    _length += sizeof(float);
    return true;
}
bool CStream::WriteShort(short data){
    CopyMemory(_buffer + _length, &data, sizeof(short));
    _length += sizeof(short);
    return true;
}
bool CStream::WriteUShort(unsigned short data){
    CopyMemory(_buffer + _length, &data, sizeof(unsigned short));
    _length += sizeof(unsigned short);
    return true;
}
bool CStream::WriteBool(bool data){
    CopyMemory(_buffer + _length, &data, sizeof(bool));
    _length += sizeof(bool);
    return true;
}
// CStream  -------------------------------

// CStreamSP ------------------------------
CStreamSP::CStreamSP()
{
    _ptr = new CStream();
    
}

CStreamSP::~CStreamSP()
{
    SAFE_DELETE(_ptr);
    
}

CStream* CStreamSP::operator->()
{
    return _ptr;
}

CStream CStreamSP::operator*()
{
    return *_ptr;
}
// CStreamSP ------------------------------

void ExampleCStream()
{
    BYTE* buffer = new BYTE[10];
    int32_t data1 = 1;
    int32_t data2 = 2;
    int32_t data3 = 3;
    
    CStream stream;
    stream.SetBuffer(buffer);
    stream.WriteInt32(data1);
    stream.WriteInt32(data2);
    stream.WriteInt32(data3);
    
    SAFE_DELETE_ARRAY(buffer);
}
