#pragma once
#include "Decimal.h"
class Complex:public NumberObject{
private:
    Decimal _realPart, _imaginePart;
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
    friend std::istream& operator>>(std::istream&, Complex&);
    
    Complex operator=(const std::string&);
    Complex operator=(const char[]);
    
    const Complex operator+(const Integer&);
    const Complex operator-(const Integer&);
    const Complex operator*(const Integer&);
    const Complex operator/(const Integer&);
    
    const Complex operator+(const Decimal&);
    const Complex operator-(const Decimal&);
    const Complex operator*(const Decimal&);
    const Complex operator/(const Decimal&);
    
    /*const Ultimate operator+(const Ultimate&);
    const Ultimate operator-(const Ultimate&);
    const Ultimate operator*(const Ultimate&);
    const Ultimate operator/(const Ultimate&);*/
    
    static Complex IntToComplex(const Integer&);
    static Complex DecimalToComplex(const Decimal&);
    static Integer ComToInteger(const Complex&);
    static Decimal ComToDecimal(const Complex&);
    const Complex Power(const Integer&);
    
    static Complex Com(const Integer&);
    static Complex Com(const Decimal&);
    static Complex Com(const Complex&);
    static Complex Com(const Ultimate&);
    
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
};
