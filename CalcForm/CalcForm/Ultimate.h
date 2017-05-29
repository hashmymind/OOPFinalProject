#pragma once
#include "NumberObject.h"
#include "Integer.h"
#include "NDecimal.h"
#include "Complex.h"

//complex + complex(sqrt(n))
class Ultimate:public NumberObject{
private:
    NDecimal n;
    Complex addend;
    Complex multiplier;
public:
    Ultimate():n(NDecimal("0")),addend(Complex("0")),multiplier(Complex("1")){};
    Ultimate(NDecimal);
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
    Ultimate operator+(NDecimal);
    Ultimate operator-(NDecimal);
    Ultimate operator*(NDecimal);
    Ultimate operator/(NDecimal);
    Ultimate operator+(Complex);
    Ultimate operator-(Complex);
    Ultimate operator*(Complex);
    Ultimate operator/(Complex);
    
    Ultimate operator=(Integer);
    Ultimate operator=(NDecimal);
    Ultimate operator=(Complex);
    
    friend Ultimate operator+(const Integer&, const Ultimate&);
    friend Ultimate operator-(const Integer&, const Ultimate&);
    friend Ultimate operator*(const Integer&, const Ultimate&);
    friend Ultimate operator/(const Integer&, const Ultimate&);
    
    friend Ultimate operator+(const NDecimal&, const Ultimate&);
    friend Ultimate operator-(const NDecimal&, const Ultimate&);
    friend Ultimate operator*(const NDecimal&, const Ultimate&);
    friend Ultimate operator/(const NDecimal&, const Ultimate&);
    
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
    static NDecimal UltToNDecimal(const Ultimate&);
    static Complex UltToComplex(const Ultimate&);
    
    static Ultimate Ult(const Integer&);
    static Ultimate Ult(const NDecimal&);
    static Ultimate Ult(const Complex&);
    static Ultimate Ult(const Ultimate&);
};
