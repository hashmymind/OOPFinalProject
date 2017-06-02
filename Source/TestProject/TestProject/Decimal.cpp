#include "Decimal.h"
#include "Complex.h"
#include "Ultimate.h"
#include "Formula.h"
//
//
// Decimal below
//
//

Decimal::Decimal(const std::string& decimalStr){
    std::string decimalTmp = decimalStr;
    this->_denominator = Integer(1, false);
    bool havePoint = false;
    for(int i=(int)decimalTmp.length()-1;i>=0;--i){
        if(decimalTmp[i] == '.'){
            decimalTmp.erase(i,1);
            havePoint = true;
            break;
        }
        this->_denominator.LeftShift();
    }
    if(!havePoint)this->_denominator = Integer(1, false);
    this->_numerator = Integer(decimalTmp);
    this->_sign = this->_numerator.GetSign();
    this->_numerator.SetSign(false);
}

Decimal Decimal::IntToDecimal(const Integer& rhs){
    Decimal newDec;
    Integer tmpInt = rhs;
    newDec._sign = tmpInt.GetSign();
    tmpInt.SetSign(false);
    newDec._numerator = tmpInt;
    newDec._denominator = Integer(1,false);
    return newDec;
}

void Decimal::Output(std::ostream& stream) const{
    stream << this->ToString(100);
}


Decimal Decimal::operator=(const std::string& numSrt){
    *this = Decimal::Dec(calc(numSrt).data);
    return *this;
}

Decimal Decimal::operator=(const char charray[]){
    *this = Decimal(std::string(charray));
    return *this;
}

Decimal::Decimal(const char charray[]){
    *this = Decimal(std::string(charray));
}

void Decimal::Reduce(){
    Integer divisor = GCD(this->_numerator, this->_denominator);
    if(divisor.ToString() == "1"){
        // todo: compare to real number
        return;
    }
    this->_numerator = this->_numerator / divisor;
    this->_denominator = this->_denominator / divisor;
    // todo: overload /=
}

const bool Decimal::GetSign() const{
    return this->_sign;
}

void Decimal::SetSign(bool sign){
    this->_sign = sign;
}

const bool Decimal::IsReduced(){
    return GCD(this->_numerator, this->_denominator) == Integer(1,false);
}

const Decimal operator+(const Decimal& lhs, const Decimal& rhs){
    // 相加再約分
    Decimal result, ltmp = lhs, rtmp = rhs;
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

const Decimal operator-(const Decimal& lhs, const Decimal& rhs){
    Decimal rtmp = rhs;
    rtmp.SetSign(!rtmp.GetSign());
    return lhs + rtmp;
}

const Decimal operator*(const Decimal& lhs, const Decimal& rhs){
    // 相乘再約分
    Decimal result;
    result._numerator = lhs._numerator * rhs._numerator;
    result._denominator = lhs._denominator * rhs._denominator;
    result.SetSign(lhs.GetSign()^rhs.GetSign());
    result.Reduce();
    return result;
}

const Decimal operator/(const Decimal& lhs, const Decimal& rhs){
    //乘倒數
    Decimal rtmp;
    rtmp._sign = rhs.GetSign();
    rtmp._numerator = rhs._denominator;
    rtmp._denominator = rhs._numerator;
    return lhs * rtmp;
}

const bool operator==(const Decimal& lhs, const Decimal& rhs){
    if(lhs._sign != rhs._sign)
        return false;
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return lnumerator == rnumerator;
}

const bool operator>(const Decimal& lhs, const Decimal& rhs){
    if(lhs._sign ^ rhs._sign){
        if(lhs._sign)return false;
        return true;
    }
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return (lnumerator > rnumerator) ^ lhs._sign;
}

const bool operator<(const Decimal& lhs, const Decimal& rhs){
    if(lhs._sign ^ rhs._sign){
        if(lhs._sign)return true;
        return false;
    }
    Integer lnumerator, rnumerator;
    lnumerator = lhs._numerator * rhs._denominator;
    rnumerator = rhs._numerator * lhs._denominator;
    return (lnumerator < rnumerator) ^ lhs._sign;
}

const bool operator>=(const Decimal& lhs, const Decimal& rhs){
    return !(lhs < rhs);
}

const bool operator<=(const Decimal& lhs, const Decimal& rhs){
    return !(lhs > rhs);
}

std::string Decimal::ToString(int precise) const{
    std::string result;
    Decimal tmp = *this;
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

const Decimal Decimal::Power(Integer rhs){
	if (rhs.IsZero()) {
		return Decimal("1");
	}
	if (rhs == Integer("1")) {
		return *this;
	}
    Decimal result = *this;
    bool Sign = rhs.GetSign();
    rhs.SetSign(false);
    result._numerator.SetSign(result._sign);
    result._numerator = result._numerator.Power(rhs);
    result._denominator = result._denominator .Power(rhs);
    result._sign = result._numerator.GetSign();
    result._numerator.SetSign(false);
    result.Reduce();
    if(Sign){
        rhs = result._numerator;
        result._numerator = result._denominator;
        result._denominator = rhs;
    }
    return result;
}

const bool Decimal::IsZero() const{
    return this->_numerator.IsZero();
}

std::string Decimal::ToString() const{
    return this->ToString(100);
}

std::ostream& operator<<(std::ostream& stream, const Decimal& rhs){
    rhs.Output(stream);
    return stream;
}

std::istream& operator>>(std::istream& stream, Decimal& rhs){
    std::string numStr;
    stream >> numStr;
    rhs = Decimal(numStr);
    return stream;
}

const Decimal Decimal::operator+(const Integer& rhs){
    return  *this + IntToDecimal(rhs);
}
const Decimal Decimal::operator-(const Integer& rhs){
    return  *this - IntToDecimal(rhs);
}
const Decimal Decimal::operator*(const Integer& rhs){
    return  *this * IntToDecimal(rhs);
}
const Decimal Decimal::operator/(const Integer& rhs){
    return  *this / IntToDecimal(rhs);
}

const Complex Decimal::operator+(const Complex& rhs){
    return  Complex::DecimalToComplex(*this) + rhs;
}
const Complex Decimal::operator-(const Complex& rhs){
    return  Complex::DecimalToComplex(*this) - rhs;
}
const Complex Decimal::operator*(const Complex& rhs){
    return  Complex::DecimalToComplex(*this) * rhs;
}
const Complex Decimal::operator/(const Complex& rhs){
    return  Complex::DecimalToComplex(*this) / rhs;
}

Decimal Decimal::Sqrt(Integer rhs){
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
    Decimal tmp;
    tmp._numerator = nVal;
    tmp._denominator = Integer("10000000000");
    tmp._sign = false;
    return tmp;
}

Decimal Decimal::Sqrt(Decimal rhs){
    if (rhs._denominator == rhs._numerator) {
        return Decimal("1");
    }
    Decimal up = Decimal::Sqrt(rhs._numerator);
    Decimal down = Decimal::Sqrt(rhs._denominator);
    return up/down;
}

Decimal Decimal::Sqrt(Complex rhs){
    return Decimal::IntToDecimal(Integer(0,false));
}

Integer Decimal::DecToInteger(const Decimal& rhs){
    Integer result =rhs._numerator/rhs._denominator;
    result.SetSign(rhs._sign);
    return result;
}

Decimal Decimal::Dec(const Integer& rhs){
    Decimal result;
    result._numerator = rhs;
    result._sign = rhs.GetSign();
    return result;
}

Decimal Decimal::Dec(const Decimal& rhs){
    return rhs;
}

Decimal Decimal::Dec(const Complex& rhs){
    return Complex::ComToDecimal(rhs);
}

Decimal Decimal::Dec(const Ultimate& rhs){
    return Ultimate::UltToDecimal(rhs);
}