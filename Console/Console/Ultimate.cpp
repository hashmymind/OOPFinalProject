#include "Ultimate.h"

Ultimate::Ultimate(Decimal newN){
    this->n = newN;
    this->multiplier = Complex("1");
}

Ultimate::Ultimate(Integer newN){
    this->n = Decimal::IntToDecimal(newN);
    this->multiplier = Complex("1");
}

Ultimate::Ultimate(Complex newN){
    this->n = Decimal("0");
    this->multiplier = Complex("1");
}

Ultimate Ultimate::operator+(Integer rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend + rhs;
    return lhs;
}

Ultimate Ultimate::operator-(Integer rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend - rhs;
    return lhs;
}

Ultimate Ultimate::operator*(Integer rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend * rhs;
    lhs.multiplier = lhs.multiplier * rhs;
    return lhs;
}

Ultimate Ultimate::operator/(Integer rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend / rhs;
    lhs.multiplier = lhs.multiplier / rhs;
    return lhs;
}

Ultimate Ultimate::operator+(Decimal rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend + rhs;
    return lhs;
}

Ultimate Ultimate::operator-(Decimal rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend - rhs;
    return lhs;
}

Ultimate Ultimate::operator*(Decimal rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend * rhs;
    lhs.multiplier = lhs.multiplier * rhs;
    return lhs;
}

Ultimate Ultimate::operator/(Decimal rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend / rhs;
    lhs.multiplier = lhs.multiplier / rhs;
    return lhs;
}

Ultimate Ultimate::operator+(Complex rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend + rhs;
    return lhs;
}

Ultimate Ultimate::operator-(Complex rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend - rhs;
    return lhs;
}

Ultimate Ultimate::operator*(Complex rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend * rhs;
    lhs.multiplier = lhs.multiplier * rhs;
    return lhs;
}

Ultimate Ultimate::operator/(Complex rhs){
    Ultimate lhs = *this;
    lhs.addend = lhs.addend / rhs;
    lhs.multiplier = lhs.multiplier / rhs;
    return lhs;
}

Ultimate Ultimate::operator=(Integer rhs){
    *this = Ultimate();
    this->addend = this->addend + rhs;
    return *this;
}

Ultimate Ultimate::operator=(Decimal rhs){
    *this = Ultimate();
    this->addend = this->addend + rhs;
    return *this;
}

Ultimate Ultimate::operator=(Complex rhs){
    *this = Ultimate();
    this->addend = this->addend + rhs;
    return *this;
}

Ultimate Ultimate::operator+(Ultimate rhs){
    Ultimate result = *this;
    if(result.n == rhs.n){
        result.addend = result.addend + rhs.addend;
        result.multiplier = result.multiplier + rhs.multiplier;
    }else{
        Decimal sqrtN = Decimal::Sqrt(rhs.n);
        result.addend  = result.addend + rhs.multiplier * sqrtN + rhs.addend;
    }
    return result;
}

Ultimate Ultimate::operator-(Ultimate rhs){
    Ultimate result = *this;
    if(result.n == rhs.n){
        result.addend = result.addend - rhs.addend;
        result.multiplier = result.multiplier - rhs.multiplier;
    }else{
        Decimal sqrtN = Decimal::Sqrt(rhs.n);
        result.addend  = result.addend - rhs.multiplier * sqrtN - rhs.addend;
    }
    return result;
}

Ultimate Ultimate::operator*(Ultimate rhs){
    Ultimate result = *this;
    if(result.n == rhs.n){
        result.addend = this->addend*rhs.addend + this->multiplier*rhs.multiplier* Complex::DecimalToComplex(result.n);
        result.multiplier = this->addend*rhs.multiplier + this->multiplier*rhs.addend;
    }
    else{
        result.addend = this->addend*rhs.addend + this->addend*rhs.multiplier*Complex::DecimalToComplex(Decimal::Sqrt(rhs.n)) + this->multiplier*rhs.addend*Complex::DecimalToComplex(Decimal::Sqrt(this->n));
        result.multiplier = this->multiplier * rhs.multiplier;
        result.n = this->n * rhs.n;
    }
    return result;
}

Ultimate Ultimate::operator/(Ultimate rhs){
    Ultimate result = *this;
    Complex demon = (rhs.addend*rhs.addend - rhs.multiplier*rhs.multiplier*Complex::DecimalToComplex(rhs.n));
    if(result.n == rhs.n){
        result.addend = (this->addend*rhs.addend - this->addend*rhs.multiplier*Complex::DecimalToComplex(Decimal::Sqrt(rhs.n)) + this->multiplier*rhs.addend*Complex::DecimalToComplex(Decimal::Sqrt(this->n))-this->multiplier*rhs.multiplier*Complex::DecimalToComplex(this->n))/demon;
        result.multiplier = Complex("0");
        result.n = Decimal("1");
    }
    else{
        result.addend = (this->addend*rhs.addend - this->addend*rhs.multiplier*Complex::DecimalToComplex(Decimal::Sqrt(rhs.n)) + this->multiplier*rhs.addend*Complex::DecimalToComplex(Decimal::Sqrt(this->n)))/demon;
        result.multiplier = (Complex("0")-this->multiplier*rhs.multiplier)/demon;
        result.n = this->n * rhs.n;
    }
    return result;
}

Complex Ultimate::ToComplex() const{
    Decimal sroot = Decimal::Sqrt(this->n);
    Complex _addend = this->addend, _multiplier = this->multiplier;
    Complex result = _addend + _multiplier * sroot;
    return result;
}

Ultimate operator+(const Integer& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator-(const Integer& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend - lhs;
    return rtmp;
}

Ultimate operator*(const Integer& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend * lhs;
    rtmp.multiplier = rtmp.multiplier * lhs;
    return rtmp;
}

Ultimate operator/(const Integer& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend / lhs;
    rtmp.multiplier = rtmp.multiplier / lhs;
    return rtmp;
}

Ultimate operator+(const Decimal& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator-(const Decimal& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator*(const Decimal& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator/(const Decimal& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator+(const Complex& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator-(const Complex& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator*(const Complex& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

Ultimate operator/(const Complex& lhs, const Ultimate& rhs){
    Ultimate rtmp = rhs;
    rtmp.addend = rtmp.addend + lhs;
    return rtmp;
}

std::string Ultimate::ToString() const{
    return this->ToComplex().ToString();
}

void Ultimate::Output(std::ostream& stream) const{
    stream << this->ToString();
}

std::ostream& operator<<(std::ostream& stream, const Ultimate& rhs){
    rhs.Output(stream);
    return stream;
}

Ultimate Ultimate::Power(Integer rhs){
    Integer one(1,false);
    Ultimate result = *this;
    bool Sign = rhs.GetSign();
    rhs.SetSign(false);
    rhs = rhs - one;
    while(!rhs.IsZero()){
        result = result * *this;
        rhs = rhs - one;
    }
    if(Sign)result = one/result;
    return result;
}

Integer Ultimate::UltToInteger(const Ultimate& rhs){
    Complex sqPart = rhs.multiplier*Complex::Com(Decimal::Sqrt(rhs.n));
    return Integer::Int(rhs.addend+sqPart);
}

Decimal Ultimate::UltToDecimal(const Ultimate& rhs){
    Complex sqPart = rhs.multiplier*Complex::Com(Decimal::Sqrt(rhs.n));
    return Decimal::Dec(rhs.addend+sqPart);
}

Complex Ultimate::UltToComplex(const Ultimate& rhs){
    Complex sqPart = rhs.multiplier*Complex::Com(Decimal::Sqrt(rhs.n));
    return rhs.addend+sqPart;
}

Ultimate Ultimate::Ult(const Integer& rhs){
    Ultimate result;
    result.addend = Complex::Com(rhs);
    return result;
}

Ultimate Ultimate::Ult(const Decimal& rhs){
    Ultimate result;
    result.addend = Complex::Com(rhs);
    return result;
}

Ultimate Ultimate::Ult(const Complex& rhs){
    Ultimate result;
    result.addend = rhs;
    return result;
}

Ultimate Ultimate::Ult(const Ultimate& rhs){
    return rhs;
}