#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>

typedef uint64_t BaseNum;

const BaseNum BaseMax = 1000000000000000000, subtrahend = BaseMax-1;
const uint32_t SizeMax = 1000, BaseLen = 18, ContainLenMax = SizeMax * BaseLen;

class Decimal;
class Complex;

class NumberObject{
    // root class
public:
    friend std::ostream& operator<<(std::ostream&, const NumberObject&);
    friend const NumberObject operator+(const NumberObject&, const NumberObject&);
    friend const NumberObject operator-(const NumberObject&, const NumberObject&);
    friend const NumberObject operator*(const NumberObject&, const NumberObject&);
    friend const NumberObject operator/(const NumberObject&, const NumberObject&);
protected:
    // Todo:在子類別實作
    virtual void Output(std::ostream&) const{};
    virtual const NumberObject Times(const NumberObject&){return *this;};
    virtual const NumberObject DivBy(const NumberObject&){return *this;};
    virtual const NumberObject Add(const NumberObject&){return *this;};
    virtual const NumberObject Sub(const NumberObject&){return *this;};
};

class Integer: public NumberObject{
private:
    std::vector<BaseNum> _digi;
    uint32_t _sizeUsed;
    bool _sign;
public:
    Integer(){}
    Integer(const std::string&);
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
    friend std::ostream& operator<<(std::ostream&, const Integer&);
    friend std::istream& operator>>(std::istream&, Integer&);
    
    void operator=(const std::string&);
    
    const Integer operator++();
    void Complete();
    void LeftShift();
    void RightShift();
    void SetSign(bool);
    const bool IsZero() const;
    const bool GetSign() const;
    std::string ToString() const;
protected:
    virtual void Output(std::ostream&) const;
};

class Decimal:public NumberObject{
private:
    Integer _numerator, _denominator;
    bool _sign;
public:
    Decimal(){}
    Decimal(const std::string&);
    
    friend const Decimal operator+(const Decimal&, const Decimal&);
    friend const Decimal operator-(const Decimal&, const Decimal&);
    friend const Decimal operator*(const Decimal&, const Decimal&);
    friend const Decimal operator/(const Decimal&, const Decimal&);
    friend const bool operator==(const Decimal&, const Decimal&);
    friend const bool operator>(const Decimal&, const Decimal&);
    friend const bool operator<(const Decimal&, const Decimal&);
    friend const bool operator>=(const Decimal&, const Decimal&);
    friend const bool operator<=(const Decimal&, const Decimal&);
    friend std::ostream& operator<<(std::ostream&, const Decimal&);
    friend std::istream& operator>>(std::istream&, Decimal&);
    
    void operator=(const std::string&);
    
    void Reduce();
    void SetSign(bool);
    const bool GetSign() const;
    const bool IsReduced();
    std::string ToString(int) const;
protected:
    virtual void Output(std::ostream&) const;
};

class Complex:public NumberObject{
private:
    Decimal _realPart, _imaginePart;
public:
    Complex(){}
    Complex(const std::string&);
    
    friend const Complex operator+(const Complex&, const Complex&);
    friend const Complex operator-(const Complex&, const Complex&);
    friend const Complex operator*(const Complex&, const Complex&);
    friend const Complex operator/(const Complex&, const Complex&);
    friend const bool operator==(const Complex&, const Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
  
protected:
    void operator=(const std::string&);
};