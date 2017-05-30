#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"
#include "Ultimate.h"
std::vector<BaseNum> Integer::primes;
//
//
// Integer below
//
//
Integer::Integer(const std::string& numStr){
    std::string numTmp = numStr;
    this->_sizeUsed = static_cast<uint32_t>(numTmp.length()) / BaseLen + 1;
    this->_digi.resize(this->_sizeUsed);
    //防呆
    if(numTmp[0] == '+')numTmp = numTmp.substr(1);
    if(numTmp == "")numTmp = "0";
    //處理負號
    this->_sign = numStr[0]=='-' ? true:false;
    numTmp = this->_sign ? numTmp.substr(1):numTmp;
    //字串補0方便轉換
    numTmp.insert(0, this->_sizeUsed*BaseLen -numTmp.length(),'0');
    //轉換
    int i=0;
    for(auto iter = std::begin(this->_digi);iter != std::end(this->_digi);++iter){
        BaseNum tmp = 0;
        for(int j=0;j<BaseLen;++j){
            tmp += static_cast<BaseNum>(pow(10,BaseLen-j-1))*(numTmp[i*BaseLen+j]-'0');
        }
        *iter = tmp;
        i++;
    }
}

Integer::Integer(BaseNum val, bool sign){
    //用數字來建構比較小的
    this->_digi.resize(1);
    this->_sign = sign;
    this->_digi[0] = val;
    this->_sizeUsed = 1;
    if(this->_digi[0]/BaseMax >0){
        this->_digi.push_back(0);
        this->_digi[1] = val%BaseMax;
        this->_digi[0] = val/BaseMax;
        this->_sizeUsed = 2;
    }
}

BaseNum Integer::Digi(){
    for(int i=this->_sizeUsed-1;i>=0;--i){
        if(this->_digi[i]){
            BaseNum digi = (BaseNum)log10(this->_digi[i]);
            digi += BaseLen*(this->_sizeUsed-1-i);
            return digi;
        }
    }
    return 0;
}

void Integer::Output(std::ostream& stream) const{
    stream << this->ToString();
}

void Integer::resize(int used){
    if(used > this->_sizeUsed){
        for(int i=this->_sizeUsed;i<used;++i){
            this->_digi.push_back(0);
            this->_sizeUsed++;
            this->RightShiftUnit();
        }
    }else if(used < this->_sizeUsed){
        for(int i=used;i<this->_sizeUsed;++i){
            this->_digi.erase(this->_digi.begin());
        }
        this->_sizeUsed = used;
    }
}

void Integer::Complete(){
    //將數字轉成10補數
    BaseNum temp;
    uint8_t carry = 1;
    for(int i=0;i<this->_sizeUsed;++i){
        this->_digi[i] = subtrahend - this->_digi[i];
    }
    auto iter = std::end(this->_digi);
    do{
        --iter;
        if(!carry)break;
        temp = *iter + carry;
        *iter = temp % BaseMax;
        carry = temp / BaseMax;
    }while(iter != std::begin(this->_digi));
}

std::string Integer::ToString() const{
    bool leading = true;
    std::string num = "", tmp;
    for(int i=0;i<this->_sizeUsed;++i){
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
    for(int i=this->_sizeUsed-1;i>=0;--i){
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

Integer Integer::operator=(const char charray[]){
    *this = Integer(std::string(charray));
    return *this;
}

Integer::Integer(const char charray[]){
    *this = Integer(std::string(charray));
}

const Integer Integer::operator=(const Integer& rhs){
    this->_sign = rhs._sign;
    this->_sizeUsed = rhs._sizeUsed;
    this->_digi = rhs._digi;
    return *this;
}

const Integer Integer::Add(const Integer& rhs) const{
    Integer ltmp = *this, rtmp = rhs;
    int len = std::max(ltmp._sizeUsed, rtmp._sizeUsed)+1;
    if(ltmp._sizeUsed < len) ltmp.resize(len);
    if(rtmp._sizeUsed < len) rtmp.resize(len);
    if(ltmp._sign){
        ltmp.Complete();
    }
    if(rtmp._sign){
        rtmp.Complete();
    }
    BaseNum carry = 0,temp;
    //加到ltmp，並假設不會溢位
    for(int i=len - 1;i>=0;--i){
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
    ltmp.autoAdjSize();
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

Integer Mul(const Integer& lhs, const Integer& rhs){
    Integer result(0, false), rtmp , itmp;
    
    for(int j=lhs._sizeUsed-1;j>=0;--j){
        rtmp = rhs;
        if(lhs._digi[j] == 0)continue;
        int count = 0;
        while(!rtmp.IsZero()){
            itmp =Integer(lhs._digi[j] * rtmp._digi[rtmp._sizeUsed-1],false);
            rtmp.RightShiftUnit();
            for(int k=0;k<count + (lhs._sizeUsed-j-1);k++){
                itmp.LeftShiftUnit();
            }count++;
            
            result = result+itmp;
        }
    }
    result._sign = lhs._sign ^ rhs._sign;
    return result;
}

Integer Karatsuba(const Integer& lhs, const Integer& rhs){
    if(lhs.IsZero()||rhs.IsZero())return Integer(0,false);
    std::string lstr = lhs.ToString(), rstr = rhs.ToString();
    if(lstr[0] == '-')lstr = lstr.substr(1);
    if(rstr[0] == '-')rstr = rstr.substr(1);
    int len = (int)std::max(lstr.length(),rstr.length()) , mid=len/2;
    if(len < 325){
        return Mul(lhs, rhs);
    }
    if(lstr.length()<len)lstr.insert(0,len-lstr.length(),'0');
    if(rstr.length()<len)rstr.insert(0,len-rstr.length(),'0');
    Integer high1(lstr.substr(0,mid)),low1(lstr.substr(mid,lstr.length()-mid));
    Integer high2(rstr.substr(0,mid)),low2(rstr.substr(mid,rstr.length()-mid));
    Integer z0 = Karatsuba(low1,low2);
    Integer z1 = Karatsuba((low1+high1),(low2+high2));
    Integer z2=Karatsuba(high1,high2);
    z1 = z1-z2-z0;
    for(int i=0;i<2*(len-mid);++i){
        z2.LeftShift();
    }
    for(int i=0;i<(len-mid);++i){
        z1.LeftShift();
    }
    return z0+z1+z2;
}

void Integer::autoAdjSize(){
    int lastZero = -1;
    for(int i=0;i<this->_sizeUsed;++i){
        if(!this->_digi[i]){
            lastZero = i;
        }else{
            break;
        }
    }
    if(lastZero != -1){
        this->resize(this->_sizeUsed - lastZero -1);
    }
}

const Integer operator*(Integer lhs,Integer rhs){
    Integer result(0, false), itmp;
    for(int j=lhs._sizeUsed-1;j>=0;--j){
        if(lhs._digi[j] == 0)continue;
        for(int i=rhs._sizeUsed-1;i>=0;--i){
            itmp =Integer(lhs._digi[j] * rhs._digi[i],false);
            for(int k=0;k<(rhs._sizeUsed -i -1) + (lhs._sizeUsed-j-1);k++){
                itmp._digi.push_back(0);
                itmp._sizeUsed++;
            }
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
    while(dividend >= divisor){
        divisor.LeftShift();
    }
    //std::cout << divisor << "\n";
    divisor.RightShift();
    //std::cout << divisor << "\n";
    while(divisor >= oriDivisor){
        result.LeftShift();
        while(dividend >= divisor){
            ++result;
            //現在不知道是調用乘法快還是用減法快，待測試
            dividend = dividend - divisor;//to do -=
            //std::cout << dividend << " " << divisor << "\n-------" << std::endl;
        }
        divisor.RightShift();
        //std::cout << dividend << " " << divisor << "\n-------" << std::endl;
    }
    result.autoAdjSize();
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

const bool operator!=(const Integer& lhs, const Integer& rhs){
    return !(lhs == rhs);
}
const bool Integer::IsZero() const{
    if(this->_sizeUsed == 0)return true;
    for(int i=this->_sizeUsed-1;i>=0;--i){
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
void Integer::LeftShiftUnit(){
    for(int i=0;i<this->_sizeUsed-1;++i){
        this->_digi[i] = this->_digi[i+1];
    }
    this->_digi[this->_sizeUsed-1] = 0;
}

void Integer::RightShiftUnit(){
    for(int i=this->_sizeUsed-1;i>0;--i){
        this->_digi[i] = this->_digi[i-1];
    }
    this->_digi[0] = 0;
}

void Integer::LeftShift(){
    /*BaseNum carry = 0, tmp, origin;
    uint32_t newSize = 0;
    for(int i=this->_sizeUsed-1;i>=0 || carry;--i){
        origin = this->_digi[i];
        tmp = this->_digi[i]*9 + carry;//先乘9
        this->_digi[i] = tmp % BaseMax;
        carry = tmp / BaseMax;
        tmp = this->_digi[i] + origin;//再加一次
        this->_digi[i] = tmp % BaseMax;
        carry += tmp / BaseMax;
        newSize = this->_sizeUsed - i;
    }
    this->_sizeUsed = newSize;*/
    *this = *this * Integer(10,false);
}

void Integer::RightShift(){
    for(int i=_sizeUsed-1;i>0;--i){
        this->_digi[i]/=10;
        this->_digi[i]+=(this->_digi[i-1]%10)*10000000;
    }
    this->_digi[0] /= 10;
    this->autoAdjSize();
}

const bool Integer::GetSign() const{
    return this->_sign;
}

void Integer::SetSign(bool sign){
    this->_sign = sign;
}

const Integer Integer::Power(Integer rhs){
    Integer one(1, false), two(2, false), tmp;
    //end Condition
    if(rhs.IsZero()){
        return one;
    }
    bool sign = rhs._sign;
    rhs._sign = false;
    if(rhs._digi[this->_sizeUsed-1]%2 == 0){
        tmp = this->Power(rhs / two);
        return (sign)?(one/(tmp * tmp)):(tmp*tmp);
    }else{
        tmp = this->Power(rhs / two);
        return (sign)?(one/(tmp * tmp * *this)):(tmp*tmp* *this);
    }
    
}

std::ostream& operator<<(std::ostream& stream, const Integer& rhs){
    rhs.Output(stream);
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

const Complex Integer::operator-(const Complex& rhs){
 return Complex::IntToComplex(*this) - rhs;
}

const Complex Integer::operator*(const Complex& rhs){
    return Complex::IntToComplex(*this) * rhs;
}

const Complex Integer::operator/(const Complex& rhs){
    return Complex::IntToComplex(*this) / rhs;
}

/*const Ultimate Integer::operator+(Ultimate rhs){
    return rhs + *this;
}*/

void Integer::LoadPrime(){
    std::ifstream fin("primes.txt");
    BaseNum tmp;
    primes.clear();
    while(fin >> tmp){
        primes.push_back(tmp);
    }
    fin.close();
}

Integer Integer::Factorial(Integer rhs){
    Integer result(1,false), one(1,false);
    /*while(!rhs.IsZero()){
        result = result * rhs;
        rhs= rhs-one;
    }*/
    // end condition
    if(rhs < one){
        return one;
    }
    //
    if(primes.size() == 0 ||  rhs > Integer(primes[primes.size()-1],false)){
        return rhs * Factorial(rhs - one);
    }else{
        BaseNum tmp = 2, tmp2,power, rhsTmp = rhs._digi[rhs._sizeUsed-1];
        for(int i=1;tmp<=rhsTmp;++i){
            power = 0;
            tmp2 = 1;
            while(true){
                tmp2 = tmp2 * tmp;
                if(tmp2 > rhsTmp)break;
                power = power + rhsTmp/tmp2;
            }
            result = result * Integer(tmp,false).Power(Integer(power,false));
            tmp = primes[i];
        }
    }
    return result;
}

Integer Integer::Int(const Integer& rhs){
    return rhs;
}

Integer Integer::Int(const Decimal& rhs){
    return Decimal::DecToInteger(rhs);
}

Integer Integer::Int(const Complex& rhs){
    return Complex::ComToInteger(rhs);
}

Integer Integer::Int(const Ultimate& rhs){
    return Ultimate::UltToInteger(rhs);
}
