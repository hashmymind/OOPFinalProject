#pragma once
//#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <cstring>
#include <cmath>

const uint64_t BaseMax = 1000000000000000000, subtrahend = BaseMax-1;;
const uint8_t SizeMax = 50, BaseLen = 18;
const uint16_t ContainLenMax = SizeMax * BaseLen;

class BigInt{
private:
    uint64_t digi[SizeMax];
    bool sign;
public:
    BigInt(){}
    BigInt(std::string);
    
    friend const BigInt operator+(const BigInt&, const BigInt&);
    friend const BigInt operator-(const BigInt&, const BigInt&);
    friend const BigInt operator*(const BigInt&, const BigInt&);
    friend const BigInt operator/(const BigInt&, const BigInt&);
    
    void Complete();
    std::string ToString();
};