#pragma once
#include <fstream>
#include "NumberObject.h"

class Integer: public NumberObject{
private:
    std::vector<BaseNum> _digi;
    uint32_t _sizeUsed;
    bool _sign;
public:
    Integer():_sizeUsed(1){
        _digi.resize(SizeMax);
    }
    Integer(const std::string&);
    Integer(BaseNum ,bool);
    Integer(const char[]);
    
    friend const Integer operator+(const Integer&, const Integer&);
    friend const Integer operator-(const Integer&, const Integer&);
    friend const Integer operator*(Integer,Integer);
    friend const Integer operator/(const Integer&, const Integer&);
    friend const Integer operator%(const Integer&, const Integer&);
    friend const bool operator>(const Integer&, const Integer&);
    friend const bool operator<(const Integer&, const Integer&);
    friend const bool operator>=(const Integer&, const Integer&);
    friend const bool operator<=(const Integer&, const Integer&);
    friend const bool operator==(const Integer&, const Integer&);
    friend const bool operator!=(const Integer&, const Integer&);
    friend const Integer GCD(const Integer&, const Integer&);
    friend std::ostream& operator<<(std::ostream&, const Integer&);
    friend std::istream& operator>>(std::istream&, Integer&);
    friend Integer Karatsuba(const Integer&, const Integer&);
    friend Integer Mul(const Integer&, const Integer&);
    
    Integer operator=(const std::string&);
    Integer operator=(const char[]);
    
    const Integer operator^(const Integer&);
    
    const Decimal operator+(const Decimal&);
    const Decimal operator-(const Decimal&);
    const Decimal operator*(const Decimal&);
    const Decimal operator/(const Decimal&);
    
    const Complex operator+(const Complex&);
    const Complex operator-(const Complex&);
    const Complex operator*(const Complex&);
    const Complex operator/(const Complex&);
    
    const Integer operator++();
    const Integer operator--();
    
    void Complete();
    void LeftShift();
    void LeftShiftUnit();
    void RightShift();
    void RightShiftUnit();
    void SetSign(bool);
    const bool IsZero() const;
    const bool GetSign() const;
    
    virtual void Output(std::ostream&) const;
    virtual void Input(std::istream&);
    virtual std::string ToString() const;
    const Integer Add(const Integer&)const;
    const Integer operator=(const Integer&);
    const Integer Power(const Integer&);
    BaseNum Digi();
    
    static Integer Factorial(Integer);
    static std::vector<BaseNum> primes;
    static void LoadPrime();
};
