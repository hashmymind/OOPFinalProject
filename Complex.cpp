#include "Complex.h"

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
        this->_realPart = Decimal(complexTmp.substr(0,end));
    }
    else{
        this->_realPart = Decimal("0");
    }
    if(haveImag){
        size_t start = 0;
        if(haveReal){
            start = midOp+1;
        }
        this->_imaginePart = Decimal(complexTmp.substr(start, complexTmp.length()-start));
        if(complexTmp[midOp]=='-')this->_imaginePart.SetSign(true);
    }
    else{
        this->_imaginePart = Decimal("0");
    }
}

std::string Complex::ToString() const{
    //還沒加入為0忽略的功能
    std::string result = "";
    result += this->_realPart.ToString(10) + " ";
    result += this->_imaginePart.GetSign()?"- "+this->_imaginePart.ToString(10).substr(1)+"i":"+ "+this->_imaginePart.ToString(10)+"i";
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
    result._realPart = lhs._realPart*rhs._realPart - lhs._imaginePart*rhs._imaginePart;
    result._imaginePart = lhs._realPart*rhs._imaginePart + lhs._imaginePart*rhs._realPart;
    return result;
}

const Complex operator/(const Complex& lhs, const Complex& rhs){
    //
    Complex result;
    Decimal divisor = rhs._realPart*rhs._realPart + rhs._imaginePart*rhs._imaginePart;
    result._realPart = (lhs._realPart*rhs._realPart + lhs._imaginePart*rhs._imaginePart)/divisor;
    result._imaginePart = (lhs._imaginePart*rhs._realPart - lhs._realPart*rhs._imaginePart)/divisor;
    return result;
}

void Complex::Output(std::ostream& stream) const{
    stream << this->ToString();
}

void Complex::Input(std::istream& stream){
    //char inputChar;
    //還不知道怎麼寫
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

std::istream& operator>>(std::istream& stream, Complex& rhs){
    rhs.Input(stream);
    return stream;
}
const bool operator==(const Complex& lhs, const Complex& rhs){
    return lhs._realPart == rhs._realPart && lhs._imaginePart == rhs._imaginePart;
}

Complex Complex::operator=(const std::string& complexStr){
    *this = Complex(complexStr);
    return *this;
}

Complex Complex::IntToComplex(const Integer& rhs){
    Complex newComp;
    newComp._realPart = Decimal::IntToDecimal(rhs);
    newComp._imaginePart = Decimal::IntToDecimal(Integer(0,false));
    return newComp;
}

Complex Complex::DecimalToComplex(const Decimal& rhs){
    Complex newComp;
    newComp._realPart = rhs;
    newComp._imaginePart = Decimal::IntToDecimal(Integer(0,false));
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

const Complex Complex::operator+(const Decimal& rhs){
    return *this + DecimalToComplex(rhs);
}
const Complex Complex::operator-(const Decimal& rhs){
    return *this - DecimalToComplex(rhs);
}
const Complex Complex::operator*(const Decimal& rhs){
    return *this * DecimalToComplex(rhs);
}
const Complex Complex::operator/(const Decimal& rhs){
    return *this / DecimalToComplex(rhs);
}
