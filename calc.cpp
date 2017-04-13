#include "calc.h"

//
//
// NumberObject below
//
//

std::ostream& operator<<(std::ostream& stream, const NumberObject& rhs){
    rhs.Output(stream);
    return stream;
}

const NumberObject operator+(const NumberObject& lhs, const NumberObject& rhs){
    return lhs.Add(rhs);
}


//
//
// Integer below
//
//

Integer::Integer(const std::string& numStr){
    std::string numTmp = numStr;
    this->_digi.resize(SizeMax);
    //防呆
    if(numTmp[0] == '+')numTmp = numTmp.substr(1);
    if(numTmp == "")numTmp = "0";
    //處理負號
    this->_sign = numStr[0]=='-' ? true:false;
    numTmp = this->_sign ? numTmp.substr(1):numTmp;
    //計算使用量
    this->_sizeUsed = static_cast<uint32_t>(numTmp.length()) / BaseLen + 1;
    //字串補0方便轉換
    numTmp.insert(0, ContainLenMax-numTmp.length(),'0');
    //轉換
    for(int i=0;i<SizeMax;++i){
        BaseNum tmp = 0;
        for(int j=0;j<BaseLen;++j){
            tmp += static_cast<BaseNum>(pow(10,BaseLen-j-1))*(numTmp[i*BaseLen+j]-'0');
        }
        this->_digi[i] = tmp;
    }
}

Integer::Integer(BaseNum val, bool sign){
    //用數字來建構比較小的
    this->_digi.resize(SizeMax);
    this->_sign = sign;
    this->_digi[SizeMax-1] = val;
    this->_sizeUsed = 1;
    if(this->_digi[SizeMax-1]/BaseMax >0){
        this->_digi[SizeMax-1] = this->_digi[SizeMax-1]%BaseMax;
        this->_digi[SizeMax-2] = val/BaseMax;
        this->_sizeUsed = 2;
    }
    
}

void Integer::Output(std::ostream& stream) const{
    stream << this->ToString();
}

void Integer::Complete(){
    //將數字轉成10補數
    BaseNum temp;
    uint8_t carry = 1;
    for(int i=0;i<SizeMax;++i){
        this->_digi[i] = subtrahend - this->_digi[i];
    }
    for(int i=SizeMax-1;i>=0;--i){
        if(!carry)break;
        temp = this->_digi[i] + carry;
        this->_digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
}

std::string Integer::ToString() const{
    bool leading = true;
    std::string num = "", tmp;
    for(int i=0;i<SizeMax;++i){
        if(!this->_digi[i] && leading)continue;
        tmp = std::to_string(this->_digi[i]);
        if(!leading)tmp.insert(0, BaseLen - tmp.length(), '0');
        num += tmp;
        if(this->_digi[i])leading = false;
    }
    if(leading)num = "0";//如果全部都是0就輸出0
    return (this->_sign?"-":"") + num;
}

const Integer Integer::operator++(){
    //prefix ++ ex:++integer
    uint8_t carry = 1;
    BaseNum temp;
    for(int i=SizeMax-1;i>=0;--i){
        if(!carry)break;
        temp = this->_digi[i] + carry;
        this->_digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
    return *this;
}

Integer Integer::operator=(const std::string& numSrt){
    *this = Integer(numSrt);
    return *this;
}

const Integer Integer::Add(const Integer& rhs) const{
    Integer ltmp = *this, rtmp = rhs;
    if(ltmp._sign)ltmp.Complete();
    if(rtmp._sign)rtmp.Complete();
    BaseNum carry = 0,temp;
    //加到ltmp，並假設不會溢位
    for(int i=SizeMax-1;i>=0;--i){
        temp = ltmp._digi[i] + rtmp._digi[i] + carry;
        ltmp._digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
    ltmp._sign = false;
    //相加結果是負數(最高為不是0，假設不會滿位)
    if(ltmp._digi[0]/(BaseMax/10)!=0){
        ltmp.Complete();
        ltmp._sign = true;
    }
    //重新計算使用量
    ltmp._sizeUsed = 1;
    for(int i = 0;i<SizeMax;++i){
        if(ltmp._digi[i]){
            ltmp._sizeUsed = SizeMax - i;
            break;
        }
    }
    return ltmp;

}

const Integer operator+(const Integer& lhs, const Integer& rhs){
    return lhs.Add(rhs);
}

const Integer operator-(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    rtmp._sign = !rtmp._sign;
    return ltmp + rtmp;
}

const Integer operator*(const Integer& lhs, const Integer& rhs){
    Integer result(0, false), rtmp=rhs , itmp;
        for(int j=SizeMax-1;j>=SizeMax-lhs._sizeUsed;--j){
            rtmp = rhs;
            if(lhs._digi[j] == 0)continue;
            int count = 0;
            while(!rtmp.IsZero()){
                if(count == 18){
                    std::cout << "";
                }
                itmp =Integer(lhs._digi[j] * (rtmp._digi[SizeMax-1]%10),false);
                rtmp.RightShift();
                for(int k=0;k<count + (SizeMax-j-1)*BaseLen;k++){
                    itmp.LeftShift();
                }count++;
                result = result+itmp;
            }
        }
    result._sign = lhs._sign ^ rhs._sign;
    return result;
}


const Integer operator/(const Integer& lhs,const Integer& rhs){
    Integer dividend = lhs, divisor = rhs, result(0,false), oriDivisor = rhs;
    dividend._sign = false;divisor._sign = false;
    if(dividend < divisor)return Integer(0,false);
    if(dividend == divisor)return Integer(1,false);
    if(divisor == Integer(1,false))return dividend;
    while(dividend >= divisor)
        divisor.LeftShift();
    divisor.RightShift();
    while(divisor >= oriDivisor){
        result.LeftShift();
        while(dividend >= divisor){
            ++result;
            //現在不知道是調用乘法快還是用減法快，待測試
            dividend = dividend - divisor;//to do -=
        }
        divisor.RightShift();
    }
    return result;
}

const Integer operator%(const Integer& lhs, const Integer& rhs){
    Integer dividend = lhs, divisor = rhs, result(0,false), oriDivisor = rhs;
    dividend._sign = false;divisor._sign = false;
    if(dividend < divisor)return dividend;
    if(dividend == divisor)return Integer(0,false);
    if(divisor == Integer(1,false))return Integer(0,false);
    while(dividend >= divisor)
        divisor.LeftShift();
    divisor.RightShift();
    while(divisor >= oriDivisor){
        result.LeftShift();
        while(dividend >= divisor){
            ++result;
            //現在不知道是調用乘法快還是用減法快，待測試
            dividend = dividend - divisor;//to do -=
        }
        divisor.RightShift();
    }
    return dividend;
}

const bool operator>(const Integer& lhs, const Integer& rhs){
    if(!(lhs._sign^rhs._sign)){
        if(lhs._sizeUsed > rhs._sizeUsed)return true;
        else if(lhs._sizeUsed < rhs._sizeUsed)return false;
        else{
            std::string lstr = lhs.ToString(), rstr = rhs.ToString();
            if(lhs._sign){
                lstr = lstr.substr(1);
                rstr = rstr.substr(1);
            }
            uint32_t maxNow = static_cast<uint32_t>(lstr.length());
            if(rstr.length()>maxNow)maxNow = static_cast<uint32_t>(rstr.length());
            lstr.insert(0, maxNow - lstr.length(), '0');
            rstr.insert(0, maxNow - rstr.length(), '0');
            return lstr > rstr;
        }
    }
    return !lhs._sign;
}

const bool operator<(const Integer& lhs, const Integer& rhs){
    if(!(lhs._sign^rhs._sign)){
        if(lhs._sizeUsed > rhs._sizeUsed)return false;
        else if(lhs._sizeUsed < rhs._sizeUsed)return true;
        else{
            std::string lstr = lhs.ToString(), rstr = rhs.ToString();
            if(lhs._sign){
                lstr = lstr.substr(1);
                rstr = rstr.substr(1);
            }
            uint32_t maxNow = static_cast<uint32_t>(lstr.length());
            if(rstr.length()>maxNow)maxNow = static_cast<uint32_t>(rstr.length());
            lstr.insert(0, maxNow - lstr.length(), '0');
            rstr.insert(0, maxNow - rstr.length(), '0');
            return lstr < rstr;
        }
    }
    return lhs._sign;
}

const bool operator>=(const Integer& lhs, const Integer& rhs){
    return !(lhs < rhs);
}

const bool operator<=(const Integer& lhs, const Integer& rhs){
    return !(lhs > rhs);
}
const bool operator==(const Integer& lhs, const Integer& rhs){
    if(!(lhs._sign^rhs._sign)){
        if(lhs._sizeUsed != rhs._sizeUsed) return false;
        else{
            std::string lstr = lhs.ToString(), rstr = rhs.ToString();
            return lstr == rstr;
        }
    }
    return false;
}

const bool Integer::IsZero() const{
    for(int i=SizeMax-1;i>=SizeMax-this->_sizeUsed;--i){
        if(this->_digi[i])return false;
    }
    return true;
}

const Integer GCD(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs, tmp;
    ltmp._sign = false;rtmp._sign = false;
    while(!rtmp.IsZero()){
        tmp = rtmp;
        rtmp = ltmp%rtmp;
        ltmp = tmp;
    }
    return ltmp;
}

void Integer::LeftShift(){
    BaseNum carry = 0, tmp, origin;
    uint32_t newSize = 0;
    for(int i=SizeMax-1;i>=SizeMax-this->_sizeUsed || carry;--i){
        origin = this->_digi[i];
        tmp = this->_digi[i]*9 + carry;//先乘9
        this->_digi[i] = tmp % BaseMax;
        carry = tmp / BaseMax;
        tmp = this->_digi[i] + origin;//再加一次
        this->_digi[i] = tmp % BaseMax;
        carry += tmp / BaseMax;
        newSize = SizeMax - i;
    }
    this->_sizeUsed = newSize;
}

void Integer::RightShift(){
    for(int i=SizeMax-1;i>=SizeMax-this->_sizeUsed;--i){
        this->_digi[i] /= 10;
        this->_digi[i] += this->_digi[i-1]%10 * (BaseMax/10);
    }
    if(!this->_digi[SizeMax - this->_sizeUsed]){
        this->_sizeUsed -= 1;
    }
}

const bool Integer::GetSign() const{
    return this->_sign;
}

void Integer::SetSign(bool sign){
    this->_sign = sign;
}

std::ostream& operator<<(std::ostream& stream, const Integer& rhs){
    rhs.Output(stream);
    return stream;
}

std::istream& operator>>(std::istream& stream, Integer& rhs){
    std::string numStr;
    stream >> numStr;
    rhs = Integer(numStr);
    return stream;
}

const Decimal Integer::operator+(const Decimal& rhs){
    return Decimal::IntToDecimal(*this) + rhs;
}

const Decimal Integer::operator-(const Decimal& rhs){
    return Decimal::IntToDecimal(*this) - rhs;
}

const Decimal Integer::operator*(const Decimal& rhs){
    return Decimal::IntToDecimal(*this) * rhs;
}

const Decimal Integer::operator/(const Decimal& rhs){
    return Decimal::IntToDecimal(*this) / rhs;
}

const Complex Integer::operator+(const Complex& rhs){
    return Complex::IntToComplex(*this) + rhs;
}

/*const Complex Integer::operator-(const Complex& rhs){
    return <#expression#>
}*/



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
    *this = Decimal(numSrt);
    return *this;
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
    if(result.length() - precise == 0) result = "0" + result ;
    if(result.length() > precise)result.insert(result.length() - precise, ".");
    if(this->_sign)result = "-" + result;
    return result;
}

std::string Decimal::ToString() const{
    return this->ToString(100);
}

std::ostream& operator<<(std::ostream& stream, const Decimal& rhs){
    rhs.Output(stream);
    return stream;
}

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
    result._imaginePart = lhs._realPart + rhs._imaginePart;
    return result;
}

const Complex operator-(const Complex& lhs, const Complex& rhs){
    Complex result;
    result._realPart = lhs._realPart - rhs._realPart;
    result._imaginePart = lhs._realPart - rhs._imaginePart;
    return result;
}

const Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex result;
    result._realPart = lhs._realPart*rhs._realPart - lhs._imaginePart*rhs._imaginePart;
    result._imaginePart = lhs._realPart*rhs._imaginePart + lhs._imaginePart*rhs._realPart;
    return result;
}

const Complex operator/(const Complex& lhs, const Complex& rhs){
    Complex result;
    Decimal divisor = lhs._realPart*lhs._realPart + rhs._imaginePart*rhs._imaginePart;
    result._realPart = (lhs._realPart*rhs._realPart + lhs._imaginePart*rhs._imaginePart)/divisor;
    result._imaginePart = (lhs._imaginePart*rhs._realPart - lhs._realPart*rhs._imaginePart)/divisor;
    return result;
}

void Complex::Output(std::ostream& stream) const{
    stream << this->ToString();
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