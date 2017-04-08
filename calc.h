#pragma once
//#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <cstring>
#include <cmath>

const uint64_t BaseMax = 1000000000000000000, subtrahend = BaseMax-1;
const uint32_t SizeMax = 100, BaseLen = 18, ContainLenMax = SizeMax * BaseLen;
class Fraction;
class BigInt{
private:
    uint64_t _digi[SizeMax];
    uint32_t _sizeUsed;
    bool _sign;
public:
    BigInt(){}
    BigInt(std::string);
    
    friend const BigInt operator+(const BigInt&, const BigInt&);
    friend const BigInt operator-(const BigInt&, const BigInt&);
    friend const BigInt operator*(const BigInt&, const BigInt&);
    friend const Fraction operator/(const BigInt&, const BigInt&);
    friend const bool operator>(const BigInt&, const BigInt&);
    friend const bool operator<(const BigInt&, const BigInt&);
    friend const bool operator==(const BigInt&, const BigInt&);
    friend const BigInt GCD(const BigInt&, const BigInt&);
    
    void Complete();
    bool isZero() const;
    std::string ToString() const;
};

class Fraction{
private:
    BigInt _numerator, _denominator;
    bool _sign;
public:
    Fraction(){}
};