#include "Decimal.h"
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
    
    Complex operator=(const std::string&);
    
    const Complex operator+(const Integer&);
    const Complex operator-(const Integer&);
    const Complex operator*(const Integer&);
    const Complex operator/(const Integer&);
    
    const Complex operator+(const Decimal&);
    const Complex operator-(const Decimal&);
    const Complex operator*(const Decimal&);
    const Complex operator/(const Decimal&);
    
    static Complex IntToComplex(const Integer&);
    static Complex DecimalToComplex(const Decimal&);
    
    virtual void Output(std::ostream&) const;
    virtual void Input(std::istream&);
    virtual std::string ToString() const;
};
