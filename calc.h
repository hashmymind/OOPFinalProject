#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>

typedef uint64_t BaseNum;

const BaseNum BaseMax = 1000000000000000000, subtrahend = BaseMax-1;
const uint32_t SizeMax = 100, BaseLen = 18, ContainLenMax = SizeMax * BaseLen;

class Decimal;
class Complex;

class Integer{
private:
    std::vector<BaseNum> _digi;
    uint32_t _sizeUsed;
    bool _sign;
public:
    Integer(){}
    Integer(std::string);
    Integer(BaseNum ,bool);
    
    friend const Integer operator+(const Integer&, const Integer&);
    friend const Integer operator-(const Integer&, const Integer&);
    friend const Integer operator*(const Integer&, const Integer&);
    friend const Integer operator/(const Integer&, const Integer&);
    friend const Integer operator%(const Integer&, const Integer&);
    friend const bool operator>(const Integer&, const Integer&);
    friend const bool operator<(const Integer&, const Integer&);
    friend const bool operator>=(const Integer&, const Integer&);
    friend const bool operator<=(const Integer&, const Integer&);
    friend const bool operator==(const Integer&, const Integer&);
    friend const Integer GCD(const Integer&, const Integer&);
    friend const std::ostream operator<<(std::ostream& stream, const Integer&);
    friend const std::istream operator>>(std::istream& stream, const Integer&);
    
    const Integer operator++();
    void Complete();
    void LeftShift();
    void RightShift();
    void SetSign(bool);
    bool IsZero() const;
    bool GetSign() const;
    std::string ToString() const;
};

class Decimal{
private:
    Integer _numerator, _denominator;
    bool _sign;
public:
    Decimal(){}
    Decimal(std::string);
    
    friend const Decimal operator+(const Decimal&, const Decimal&);
    friend const Decimal operator-(const Decimal&, const Decimal&);
    friend const Decimal operator*(const Decimal&, const Decimal&);
    friend const Decimal operator/(const Decimal&, const Decimal&);
    friend const bool operator==(const Decimal&, const Decimal&);
    friend const std::ostream operator<<(std::ostream& stream, const Decimal&);
    friend const std::istream operator>>(std::istream& stream, const Decimal&);
    
    void Reduce();
    void SetSign(bool);
    bool GetSign() const;
    bool IsReduced();
    std::string ToString() const;
};

class Complex{
private:
    Decimal _realPart, _imaginePart;
public:
    Complex(){}
    
};