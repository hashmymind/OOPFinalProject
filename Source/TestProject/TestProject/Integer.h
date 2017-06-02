#pragma once
#include <fstream>
#include "NumberObject.h"

class Integer: public NumberObject{
private:
    std::vector<BaseNum> _digi;
    uint32_t _sizeUsed;
    bool _sign;
public:
    Integer():_sizeUsed(1),_sign(false){
        _digi.resize(1);
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
    
    /*const Ultimate operator+(Ultimate);
    const Ultimate operator-(Ultimate);
    const Ultimate operator*(Ultimate);
    const Ultimate operator/(Ultimate);*/
    
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
    void resize(int used);
    void autoAdjSize();
    
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
    const Integer Add(const Integer&)const;
    const Integer operator=(const Integer&);
    const Integer Power(Integer);
    BaseNum Digi();
    
    static Integer Int(const Integer&);
    static Integer Int(const Decimal&);
    static Integer Int(const Complex&);
    static Integer Int(const Ultimate&);
    
    static Integer Factorial(Integer);
    static std::vector<BaseNum> primes;
    static void LoadPrime();
};
