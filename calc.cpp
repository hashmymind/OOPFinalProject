#include "calc.h"

Integer::Integer(std::string numStr){
    this->_sign = numStr[0]=='-' ? true:false;
    numStr = this->_sign ? numStr.substr(1):numStr;
    this->_sizeUsed = static_cast<uint32_t>(numStr.length()) / BaseLen + 1;
    numStr.insert(0, ContainLenMax-numStr.length(),'0');
    for(int i=0;i<SizeMax;++i){
        uint64_t tmp = 0;
        for(int j=0;j<BaseLen;++j){
            tmp += static_cast<uint64_t>(pow(10,BaseLen-j-1))*(numStr[i*BaseLen+j]-'0');
        }
        this->_digi[i] = tmp;
    }
}

void Integer::Complete(){
    //將數字轉成10補數
    uint64_t temp;
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
    if(leading)num = "0";
    return (this->_sign?"-":"") + num;
}

const Integer operator+(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    if(ltmp._sign)ltmp.Complete();
    if(rtmp._sign)rtmp.Complete();
    uint64_t carry = 0,temp;
    //加到ltmp，並假設不會溢位
    for(int i=SizeMax-1;i>=0;--i){
        if(!carry && i<(SizeMax - ltmp._sizeUsed) && i<(SizeMax - rtmp._sizeUsed))break;
        temp = ltmp._digi[i] + rtmp._digi[i] + carry;
        ltmp._digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
    ltmp._sign = false;
    if(ltmp._digi[0]/(BaseMax/10)!=0){
        //相加結果是負數(最高為不是0，假設不會滿位)
        ltmp.Complete();
        ltmp._sign = true;
    }
    return ltmp;
}

const Integer operator-(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    rtmp._sign = !rtmp._sign;
    return ltmp + rtmp;
}

const Integer operator*(const Integer& lhs, const Integer& rhs){
    Integer result("0");
    uint64_t tmp;
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
            }
        }
    }
    result._sign = lhs._sign ^ rhs._sign;
    return result;
}

const bool operator>(const Integer& lhs, const Integer& rhs){
    if(!(lhs._sign^rhs._sign)){
        if(lhs._sizeUsed > rhs._sizeUsed)return !lhs._sizeUsed;
        else if(lhs._sizeUsed < rhs._sizeUsed)return lhs._sizeUsed;
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
        if(lhs._sizeUsed > rhs._sizeUsed)return lhs._sizeUsed;
        else if(lhs._sizeUsed < rhs._sizeUsed)return !lhs._sizeUsed;
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

inline bool Integer::isZero() const{
    for(int i=SizeMax-1;i>=SizeMax-this->_sizeUsed;--i){
        if(this->_digi[i])return false;
    }
    return true;
}

const Integer GCD(const Integer& lhs, const Integer& rhs){
    Integer ltmp = lhs, rtmp = rhs;
    ltmp._sign = false;rtmp._sign = false;
    while(!rtmp.isZero()){
        if(ltmp > rtmp){
            ltmp = ltmp - rtmp;
        }
        else{
            rtmp = rtmp - ltmp;
        }
    }
    return ltmp;
}