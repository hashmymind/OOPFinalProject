#include "calc.h"

//
//
// Integer below
//
//

Integer::Integer(std::string numStr){
    this->_digi.resize(SizeMax);
    //處理負號
    this->_sign = numStr[0]=='-' ? true:false;
    numStr = this->_sign ? numStr.substr(1):numStr;
    //計算使用量
    this->_sizeUsed = static_cast<uint32_t>(numStr.length()) / BaseLen + 1;
    //字串補0方便轉換
    numStr.insert(0, ContainLenMax-numStr.length(),'0');
    //轉換
    for(int i=0;i<SizeMax;++i){
        BaseNum tmp = 0;
        for(int j=0;j<BaseLen;++j){
            tmp += static_cast<BaseNum>(pow(10,BaseLen-j-1))*(numStr[i*BaseLen+j]-'0');
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

const Integer operator+(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    if(ltmp._sign)ltmp.Complete();
    if(rtmp._sign)rtmp.Complete();
    BaseNum carry = 0,temp;
    //加到ltmp，並假設不會溢位
    for(int i=SizeMax-1;i>=0;--i){
        if(!carry && i<(SizeMax - ltmp._sizeUsed) && i<(SizeMax - rtmp._sizeUsed))break;
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
    for(int i = 0;i<SizeMax;++i){
        if(ltmp._digi[i]){
            ltmp._sizeUsed = SizeMax - i;
            break;
        }
    }
    return ltmp;
}

const Integer operator-(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    rtmp._sign = !rtmp._sign;
    return ltmp + rtmp;
}

const Integer operator*(const Integer& lhs, const Integer& rhs){
    Integer result(0, false);
    BaseNum tmp;
    for(int i=SizeMax-1;i>=SizeMax-rhs._sizeUsed;--i){
        //i for rhs j for lhs
        if(rhs._digi[i] == 0)continue;
        for(int j=SizeMax-1;j>=SizeMax-lhs._sizeUsed;--j){
            if(lhs._digi[j] == 0)continue;
            tmp = lhs._digi[j] * rhs._digi[i];
            for(int k=0;tmp;++k){
                tmp = result._digi[i-(SizeMax-j)+1-k] + tmp;
                result._digi[i-(SizeMax-j)+1-k] = tmp % BaseMax;
                tmp /= BaseMax;
                //重新計算使用量
                result._sizeUsed = SizeMax - (i-(SizeMax-j)+1-k);
            }
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

inline bool Integer::IsZero() const{
    for(int i=SizeMax-1;i>=SizeMax-this->_sizeUsed;--i){
        if(this->_digi[i])return false;
    }
    return true;
}

const Integer GCD(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    ltmp._sign = false;rtmp._sign = false;
    while(!rtmp.IsZero()){
        if(ltmp > rtmp){
            ltmp = ltmp - rtmp;
        }
        else{
            rtmp = rtmp - ltmp;
        }
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

bool Integer::GetSign() const{
    return this->_sign;
}

void Integer::SetSign(bool sign){
    this->_sign = sign;
}

//
//
// Decimal below
//
//

Decimal::Decimal(std::string decimalStr){
    this->_denominator = Integer(1, false);
    bool havePoint = false;
    for(int i=(int)decimalStr.length()-1;i>=0;--i){
        if(decimalStr[i] == '.'){
            decimalStr.erase(i,1);
            havePoint = true;
            break;
        }
        this->_denominator.LeftShift();
    }
    if(!havePoint)this->_denominator = Integer(1, false);
    this->_numerator = Integer(decimalStr);
    this->_sign = this->_numerator.GetSign();
    this->_numerator.SetSign(false);
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

bool Decimal::GetSign() const{
    return this->_sign;
}

void Decimal::SetSign(bool sign){
    this->_sign = sign;
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
