#pragma once
#include "Integer.h"

class NDecimal:public NumberObject{
private:
    Integer _numerator, _denominator;
    bool _sign;
public:
    NDecimal(){
        _numerator = Integer(0, false);
        _denominator = Integer(1, false);
    }
    NDecimal(const std::string&);
    NDecimal(const char[]);
    
    friend const NDecimal operator+(const NDecimal&, const NDecimal&);
    friend const NDecimal operator-(const NDecimal&, const NDecimal&);
    friend const NDecimal operator*(const NDecimal&, const NDecimal&);
    friend const NDecimal operator/(const NDecimal&, const NDecimal&);
    friend const bool operator==(const NDecimal&, const NDecimal&);
    friend const bool operator>(const NDecimal&, const NDecimal&);
    friend const bool operator<(const NDecimal&, const NDecimal&);
    friend const bool operator>=(const NDecimal&, const NDecimal&);
    friend const bool operator<=(const NDecimal&, const NDecimal&);
    friend std::ostream& operator<<(std::ostream&, const NDecimal&);
    
    NDecimal operator=(const std::string&);
    NDecimal operator=(const char[]);
    
    const NDecimal operator+(const Integer&);
    const NDecimal operator-(const Integer&);
    const NDecimal operator*(const Integer&);
    const NDecimal operator/(const Integer&);
    
    const Complex operator+(const Complex&);
    const Complex operator-(const Complex&);
    const Complex operator*(const Complex&);
    const Complex operator/(const Complex&);
    
    /*const Ultimate operator+(const Ultimate&);
    const Ultimate operator-(const Ultimate&);
    const Ultimate operator*(const Ultimate&);
    const Ultimate operator/(const Ultimate&);*/
    
    void Reduce();
    void SetSign(bool);
    const bool GetSign() const;
    const bool IsReduced();
    const bool IsZroe() const;
    std::string ToString(int) const;
    const NDecimal Power(const Integer&);
    
    static NDecimal IntToNDecimal(const Integer&);
    static Integer DecToInteger(const NDecimal&);
    static NDecimal Sqrt(Integer);
    static NDecimal Sqrt(NDecimal);
    static NDecimal Sqrt(Complex); //just for compiler
    
    static NDecimal Dec(const Integer&);
    static NDecimal Dec(const NDecimal&);
    static NDecimal Dec(const Complex&);
    static NDecimal Dec(const Ultimate&);
    
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
};
