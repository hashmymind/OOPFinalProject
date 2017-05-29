#pragma once
#include "NDecimal.h"
class Complex:public NumberObject{
private:
    NDecimal _realPart, _imaginePart;
public:
    Complex(){}
    Complex(const std::string&);
    Complex(const char[]);
    
    friend const Complex operator+(const Complex&, const Complex&);
    friend const Complex operator-(const Complex&, const Complex&);
    friend const Complex operator*(const Complex&, const Complex&);
    friend const Complex operator/(const Complex&, const Complex&);
    friend const bool operator==(const Complex&, const Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    
    Complex operator=(const std::string&);
    Complex operator=(const char[]);
    
    const Complex operator+(const Integer&);
    const Complex operator-(const Integer&);
    const Complex operator*(const Integer&);
    const Complex operator/(const Integer&);
    
    const Complex operator+(const NDecimal&);
    const Complex operator-(const NDecimal&);
    const Complex operator*(const NDecimal&);
    const Complex operator/(const NDecimal&);
    
    /*const Ultimate operator+(const Ultimate&);
    const Ultimate operator-(const Ultimate&);
    const Ultimate operator*(const Ultimate&);
    const Ultimate operator/(const Ultimate&);*/
    
    static Complex IntToComplex(const Integer&);
    static Complex NDecimalToComplex(const NDecimal&);
    static Integer ComToInteger(const Complex&);
    static NDecimal ComToNDecimal(const Complex&);
    const Complex Power(const Integer&);
    
    static Complex Com(const Integer&);
    static Complex Com(const NDecimal&);
    static Complex Com(const Complex&);
    static Complex Com(const Ultimate&);
    
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
};
