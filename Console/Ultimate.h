#pragma once
#include "NumberObject.h"
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

//complex + complex(sqrt(n))
class Ultimate:public NumberObject{
private:
    Decimal n;
    Complex addend;
    Complex multiplier;
public:
    Ultimate():n(Decimal("0")),addend(Complex("0")),multiplier(Complex("1")){};
    Ultimate(Decimal);
    Ultimate(Integer);
    Ultimate(Complex);//for compiler
    
    Ultimate operator+(Ultimate);
    Ultimate operator-(Ultimate);
    Ultimate operator*(Ultimate);
    Ultimate operator/(Ultimate);
    
    Ultimate operator+(Integer);
    Ultimate operator-(Integer);
    Ultimate operator*(Integer);
    Ultimate operator/(Integer);
    Ultimate operator+(Decimal);
    Ultimate operator-(Decimal);
    Ultimate operator*(Decimal);
    Ultimate operator/(Decimal);
    Ultimate operator+(Complex);
    Ultimate operator-(Complex);
    Ultimate operator*(Complex);
    Ultimate operator/(Complex);
    
    Ultimate operator=(Integer);
    Ultimate operator=(Decimal);
    Ultimate operator=(Complex);
    
    friend Ultimate operator+(const Integer&, const Ultimate&);
    friend Ultimate operator-(const Integer&, const Ultimate&);
    friend Ultimate operator*(const Integer&, const Ultimate&);
    friend Ultimate operator/(const Integer&, const Ultimate&);
    
    friend Ultimate operator+(const Decimal&, const Ultimate&);
    friend Ultimate operator-(const Decimal&, const Ultimate&);
    friend Ultimate operator*(const Decimal&, const Ultimate&);
    friend Ultimate operator/(const Decimal&, const Ultimate&);
    
    friend Ultimate operator+(const Complex&, const Ultimate&);
    friend Ultimate operator-(const Complex&, const Ultimate&);
    friend Ultimate operator*(const Complex&, const Ultimate&);
    friend Ultimate operator/(const Complex&, const Ultimate&);
    
    Complex ToComplex() const;
    friend std::ostream& operator<<(std::ostream&, const Ultimate&);
    virtual void Output(std::ostream&) const;
    virtual std::string ToString() const;
    Ultimate Power(Integer);
    static Integer UltToInteger(const Ultimate&);
    static Decimal UltToDecimal(const Ultimate&);
    static Complex UltToComplex(const Ultimate&);
    
    static Ultimate Ult(const Integer&);
    static Ultimate Ult(const Decimal&);
    static Ultimate Ult(const Complex&);
    static Ultimate Ult(const Ultimate&);
};
