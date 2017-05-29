#include "Complex.h"
#include "Ultimate.h"

//
//
// Complex below
//
//

Complex::Complex(const std::string& complexStr){
    //邏輯有點亂 有空改
    std::string complexTmp = complexStr;
    bool haveReal = false, haveImag = false;
    if(complexTmp.find("i") != std::string::npos){
        haveImag = true;
        complexTmp.erase(complexTmp.find("i"),1);
    }
    if((!haveImag && complexTmp.size()!=0)|| complexTmp.find("+",1)!=std::string::npos||complexTmp.find("-",1)!=std::string::npos){
        haveReal = true;
    }
    size_t midOp = complexTmp.find("+",1);
    if(midOp ==std::string::npos)midOp =complexTmp.find("-",1);
    if(haveReal){
        size_t end = complexTmp.length();
        if(haveImag)
            end = midOp;
        this->_realPart = NDecimal(complexTmp.substr(0,end));
    }
    else{
        this->_realPart = NDecimal("0");
    }
    if(haveImag){
        size_t start = 0;
        if(haveReal){
            start = midOp+1;
        }
        std::string img = complexTmp.substr(start, complexTmp.length()-start);
        if(img == "")img="1";
        this->_imaginePart = NDecimal(img);
        if(midOp !=std::string::npos && complexTmp[midOp]=='-')this->_imaginePart.SetSign(true);
    }
    else{
        this->_imaginePart = NDecimal("0");
    }
}

std::string Complex::ToString() const{
    std::string result = "";
    bool haveReal = !this->_realPart.IsZroe();
    bool haveImag = !this->_imaginePart.IsZroe();
    if(haveReal || !haveImag)result += this->_realPart.ToString(100);
    if(haveImag){
        std::string addSign = haveReal?"+":"";
        result += this->_imaginePart.GetSign()?"-"+this->_imaginePart.ToString(10).substr(1)+"i":addSign+this->_imaginePart.ToString(10)+"i";
    }
    return result;
}

const Complex operator+(const Complex& lhs, const Complex& rhs){
    Complex result;
    result._realPart = lhs._realPart + rhs._realPart;
    result._imaginePart = lhs._imaginePart + rhs._imaginePart;
    return result;
}

const Complex operator-(const Complex& lhs, const Complex& rhs){
    Complex result;
    result._realPart = lhs._realPart - rhs._realPart;
    result._imaginePart = lhs._imaginePart - rhs._imaginePart;
    return result;
}

const Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex result;
    NDecimal de1,de2;
    
    result._realPart = lhs._realPart*rhs._realPart - lhs._imaginePart*rhs._imaginePart;
    result._imaginePart = lhs._realPart*rhs._imaginePart + lhs._imaginePart*rhs._realPart;
    return result;
}

const Complex operator/(const Complex& lhs, const Complex& rhs){
    //
    Complex result;
    NDecimal divisor = rhs._realPart*rhs._realPart + rhs._imaginePart*rhs._imaginePart;
    result._realPart = (lhs._realPart*rhs._realPart + lhs._imaginePart*rhs._imaginePart)/divisor;
    result._imaginePart = (lhs._imaginePart*rhs._realPart - lhs._realPart*rhs._imaginePart)/divisor;
    return result;
}

void Complex::Output(std::ostream& stream) const{
    stream << this->ToString();
}

const Complex Complex::Power(const Integer& rhs){
    Complex result = *this;
    Integer times = rhs, one(1, false);
    times = times - one;
    while(!times.IsZero()){
        result = result * *this;
        times = times - one;
    }
    return result;
}

std::ostream& operator<<(std::ostream& stream, const Complex& rhs){
    rhs.Output(stream);
    return stream;
}
const bool operator==(const Complex& lhs, const Complex& rhs){
    return lhs._realPart == rhs._realPart && lhs._imaginePart == rhs._imaginePart;
}

Complex Complex::operator=(const std::string& complexStr){
    *this = Complex(complexStr);
    return *this;
}

Complex Complex::operator=(const char charray[]){
    *this = Complex(std::string(charray));
    return *this;
}
Complex::Complex(const char charray[]){
    *this = Complex(std::string(charray));
}

Complex Complex::IntToComplex(const Integer& rhs){
    Complex newComp;
    newComp._realPart = NDecimal::IntToNDecimal(rhs);
    newComp._imaginePart = NDecimal::IntToNDecimal(Integer(0,false));
    return newComp;
}

Complex Complex::NDecimalToComplex(const NDecimal& rhs){
    Complex newComp;
    newComp._realPart = rhs;
    newComp._imaginePart = NDecimal::IntToNDecimal(Integer(0,false));
    return newComp;
}

const Complex Complex::operator+(const Integer& rhs){
    return *this + IntToComplex(rhs);
}
const Complex Complex::operator-(const Integer& rhs){
    return *this - IntToComplex(rhs);
}
const Complex Complex::operator*(const Integer& rhs){
    return *this * IntToComplex(rhs);
}
const Complex Complex::operator/(const Integer& rhs){
    return *this / IntToComplex(rhs);
}

const Complex Complex::operator+(const NDecimal& rhs){
    return *this + NDecimalToComplex(rhs);
}
const Complex Complex::operator-(const NDecimal& rhs){
    return *this - NDecimalToComplex(rhs);
}
const Complex Complex::operator*(const NDecimal& rhs){
    return *this * NDecimalToComplex(rhs);
}
const Complex Complex::operator/(const NDecimal& rhs){
    return *this / NDecimalToComplex(rhs);
}

Integer Complex::ComToInteger(const Complex& rhs){
    return NDecimal::DecToInteger(rhs._realPart);
}

NDecimal Complex::ComToNDecimal(const Complex& rhs){
    return rhs._realPart;
}

Complex Complex::Com(const Integer& rhs){
    return Complex::IntToComplex(rhs);
}

Complex Complex::Com(const NDecimal& rhs){
    return Complex::NDecimalToComplex(rhs);
}

Complex Complex::Com(const Complex& rhs){
    return rhs;
}

Complex Complex::Com(const Ultimate& rhs){
    return Ultimate::UltToComplex(rhs);
}