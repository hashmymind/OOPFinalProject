#pragma once
#include "Integer.h"

class Decimal:public NumberObject{
private:
    Integer _numerator, _denominator;
    bool _sign;
public:
    Decimal(){
        _numerator = Integer(0, false);
        _denominator = Integer(1, false);
    }
    Decimal(const std::string&);
    Decimal(const char[]);
    
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
    
    Decimal operator=(const std::string&);
    Decimal operator=(const char[]);
    
    const Decimal operator+(const Integer&);
    const Decimal operator-(const Integer&);
    const Decimal operator*(const Integer&);
    const Decimal operator/(const Integer&);
    
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
    const Decimal Power(const Integer&);
    
    static Decimal IntToDecimal(const Integer&);
    static Integer DecToInteger(const Decimal&);
    static Decimal Sqrt(Integer);
    static Decimal Sqrt(Decimal);
    static Decimal Sqrt(Complex); //just for compiler
    
    static Decimal Dec(const Integer&);
    static Decimal Dec(const Decimal&);
    static Decimal Dec(const Complex&);
    static Decimal Dec(const Ultimate&);
    
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
};
