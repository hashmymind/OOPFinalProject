#include "NDecimal.h"
#include "Complex.h"
#include "Ultimate.h"
//
//
// NDecimal below
//
//

NDecimal::NDecimal(const std::string& NDecimalStr){
    std::string NDecimalTmp = NDecimalStr;
    this->_denominator = Integer(1, false);
    bool havePoint = false;
    for(int i=(int)NDecimalTmp.length()-1;i>=0;--i){
        if(NDecimalTmp[i] == '.'){
            NDecimalTmp.erase(i,1);
            havePoint = true;
            break;
        }
        this->_denominator.LeftShift();
    }
    if(!havePoint)this->_denominator = Integer(1, false);
    this->_numerator = Integer(NDecimalTmp);
    this->_sign = this->_numerator.GetSign();
    this->_numerator.SetSign(false);
}

NDecimal NDecimal::IntToNDecimal(const Integer& rhs){
    NDecimal newDec;
    Integer tmpInt = rhs;
    newDec._sign = tmpInt.GetSign();
    tmpInt.SetSign(false);
    newDec._numerator = tmpInt;
    newDec._denominator = Integer(1,false);
    return newDec;
}

void NDecimal::Output(std::ostream& stream) const{
    stream << this->ToString(100);
}


NDecimal NDecimal::operator=(const std::string& numSrt){
    *this = NDecimal(numSrt);
    return *this;
}

NDecimal NDecimal::operator=(const char charray[]){
    *this = NDecimal(std::string(charray));
    return *this;
}

NDecimal::NDecimal(const char charray[]){
    *this = NDecimal(std::string(charray));
}

void NDecimal::Reduce(){
    Integer divisor = GCD(this->_numerator, this->_denominator);
    if(divisor.ToString() == "1"){
        // todo: compare to real number
        return;
    }
    this->_numerator = this->_numerator / divisor;
    this->_denominator = this->_denominator / divisor;
    // todo: overload /=
}

const bool NDecimal::GetSign() const{
    return this->_sign;
}

void NDecimal::SetSign(bool sign){
    this->_sign = sign;
}

const bool NDecimal::IsReduced(){
    return GCD(this->_numerator, this->_denominator) == Integer(1,false);
}

const NDecimal operator+(const NDecimal& lhs, const NDecimal& rhs){
    // 相加再約分
    NDecimal result, ltmp = lhs, rtmp = rhs;
    ltmp._numerator.SetSign(ltmp.GetSign());
    ltmp._denominator.SetSign(false);
    rtmp._numerator.SetSign(rtmp.GetSign());
    rtmp._denominator.SetSign(false);
    result._numerator = ltmp._numerator*rtmp._denominator + ltmp._denominator*rtmp._numerator;
    result._denominator = ltmp._denominator * rtmp._denominator;
    result.SetSign(result._numerator.GetSign());
    result._numerator.SetSign(false);
    result.Reduce();
    return result;
}

const NDecimal operator-(const NDecimal& lhs, const NDecimal& rhs){
    NDecimal rtmp = rhs;
    rtmp.SetSign(!rtmp.GetSign());
    return lhs + rtmp;
}

const NDecimal operator*(const NDecimal& lhs, const NDecimal& rhs){
    // 相乘再約分
    NDecimal result;
    result._numerator = lhs._numerator * rhs._numerator;
    result._denominator = lhs._denominator * rhs._denominator;
    result.SetSign(lhs.GetSign()^rhs.GetSign());
    result.Reduce();
    return result;
}

const NDecimal operator/(const NDecimal& lhs, const NDecimal& rhs){
    //乘倒數
    NDecimal rtmp;
    rtmp._sign = rhs.GetSign();
    rtmp._numerator = rhs._denominator;
    rtmp._denominator = rhs._numerator;
    return lhs * rtmp;
}

const bool operator==(const NDecimal& lhs, const NDecimal& rhs){
    if(lhs._sign != rhs._sign)
        return false;
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return lnumerator == rnumerator;
}

const bool operator>(const NDecimal& lhs, const NDecimal& rhs){
    if(lhs._sign ^ rhs._sign){
        if(lhs._sign)return false;
        return true;
    }
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return (lnumerator > rnumerator) ^ lhs._sign;
}

const bool operator<(const NDecimal& lhs, const NDecimal& rhs){
    if(lhs._sign ^ rhs._sign){
        if(lhs._sign)return true;
        return false;
    }
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return (lnumerator < rnumerator) ^ lhs._sign;
}

const bool operator>=(const NDecimal& lhs, const NDecimal& rhs){
    return !(lhs < rhs);
}

const bool operator<=(const NDecimal& lhs, const NDecimal& rhs){
    return !(lhs > rhs);
}

std::string NDecimal::ToString(int precise) const{
    std::string result;
    NDecimal tmp = *this;
    for(int i=0;i<precise;++i){
        tmp._numerator.LeftShift();
    }
    tmp.Reduce();
    result = (tmp._numerator / tmp._denominator).ToString();
    if(result.size() <= precise)result.insert(0, precise - result.length()+1,'0');
    result.insert(result.length() - precise, ".");
    //claer lasting zero
    int lasting = (int)result.length()-1;
    for(;lasting>0;--lasting){
        if(result[lasting]=='.'){
            --lasting;
            break;
        }
        if(result[lasting]!='0')break;
    }
    result = result.substr(0,lasting+1);
    if(this->_sign)result = "-" + result;
    return result;
}

const NDecimal NDecimal::Power(const Integer& rhs){
    NDecimal result = *this;
    result._numerator.SetSign(result._sign);
    result._numerator = result._numerator.Power(rhs);
    result._denominator = result._denominator .Power(rhs);
    result._sign = result._numerator.GetSign();
    result._numerator.SetSign(false);
    result.Reduce();
    return result;
}

const bool NDecimal::IsZroe() const{
    return this->_numerator.IsZero();
}

std::string NDecimal::ToString() const{
    return this->ToString(100);
}

std::ostream& operator<<(std::ostream& stream, const NDecimal& rhs){
    rhs.Output(stream);
    return stream;
}

const NDecimal NDecimal::operator+(const Integer& rhs){
    return  *this + IntToNDecimal(rhs);
}
const NDecimal NDecimal::operator-(const Integer& rhs){
    return  *this - IntToNDecimal(rhs);
}
const NDecimal NDecimal::operator*(const Integer& rhs){
    return  *this * IntToNDecimal(rhs);
}
const NDecimal NDecimal::operator/(const Integer& rhs){
    return  *this / IntToNDecimal(rhs);
}

const Complex NDecimal::operator+(const Complex& rhs){
    return  Complex::NDecimalToComplex(*this) + rhs;
}
const Complex NDecimal::operator-(const Complex& rhs){
    return  Complex::NDecimalToComplex(*this) - rhs;
}
const Complex NDecimal::operator*(const Complex& rhs){
    return  Complex::NDecimalToComplex(*this) * rhs;
}
const Complex NDecimal::operator/(const Complex& rhs){
    return  Complex::NDecimalToComplex(*this) / rhs;
}

NDecimal NDecimal::Sqrt(Integer rhs){
    for(int i=0;i<SqrtPrecise *2;++i)
        rhs.LeftShift();
    Integer two(2,false),nVal, val = rhs;
    BaseNum digi = rhs.Digi()/2;
    for(int i=0;i<digi;++i)
        val.RightShift();
    val = val/two;
    nVal = (val + (rhs/val))/two;
    while(nVal != val){
        val = nVal;
        nVal = (val + (rhs/val))/two;
    }
    NDecimal tmp;
    tmp._numerator = nVal;
    tmp._denominator = Integer("10000000000");
    tmp._sign = false;
    return tmp;
}

NDecimal NDecimal::Sqrt(NDecimal rhs){
    NDecimal up = NDecimal::Sqrt(rhs._numerator);
    NDecimal down = NDecimal::Sqrt(rhs._denominator);
    return up/down;
}

NDecimal NDecimal::Sqrt(Complex rhs){
    return NDecimal::IntToNDecimal(Integer(0,false));
}

Integer NDecimal::DecToInteger(const NDecimal& rhs){
    return rhs._numerator/rhs._denominator;
}

NDecimal NDecimal::Dec(const Integer& rhs){
    NDecimal result;
    result._numerator = rhs;
    result._sign = rhs.GetSign();
    return result;
}

NDecimal NDecimal::Dec(const NDecimal& rhs){
    return rhs;
}

NDecimal NDecimal::Dec(const Complex& rhs){
    return Complex::ComToNDecimal(rhs);
}

NDecimal NDecimal::Dec(const Ultimate& rhs){
    return Ultimate::UltToNDecimal(rhs);
}