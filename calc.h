#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <cstring>
#include <cmath>

const uint64_t BaseMax = 1000000000000000000, subtrahend = BaseMax-1;
const uint32_t SizeMax = 100, BaseLen = 18, ContainLenMax = SizeMax * BaseLen;
class Decimal;
class Integer{
private:
    uint64_t _digi[SizeMax];
    uint32_t _sizeUsed;
    bool _sign;
public:
    Integer(){}
    Integer(std::string);
    
    friend const Integer operator+(const Integer&, const Integer&);
    friend const Integer operator-(const Integer&, const Integer&);
    friend const Integer operator*(const Integer&, const Integer&);
    friend const Decimal operator/(const Integer&, const Integer&);
    friend const bool operator>(const Integer&, const Integer&);
    friend const bool operator<(const Integer&, const Integer&);
    friend const bool operator==(const Integer&, const Integer&);
    friend const Integer GCD(const Integer&, const Integer&);
    friend const std::ostream operator<<(std::ostream& stream, const Integer&);
    friend const std::istream operator>>(std::istream& stream, const Integer&);
    
    void Complete();
    bool isZero() const;
    std::string ToString() const;
};

class Decimal{
private:
    Integer _numerator, _denominator;
    bool _sign;
public:
    Decimal(){}
    
};

class Complex{
private:
    Decimal _realPart, _imaginePart;
public:
    Complex(){}
    
};