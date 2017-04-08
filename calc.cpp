#include "calc.h"

BigInt::BigInt(std::string numStr){
    this->sign = numStr[0]=='-' ? true:false;
    numStr = this->sign ? numStr.substr(1):numStr;
    numStr.insert(0, ContainLenMax-numStr.length(),'0');
    for(int i=0;i<SizeMax;++i){
        uint64_t tmp = 0;
        for(int j=0;j<BaseLen;++j){
            tmp += static_cast<uint64_t>(pow(10,BaseLen-j-1))*(numStr[i*BaseLen+j]-'0');
        }
        this->digi[i] = tmp;
    }
}

void BigInt::Complete(){
    //將數字轉成10補數
    uint64_t temp;
    uint8_t carry = 1;
    for(int i=0;i<SizeMax;++i){
        this->digi[i] = subtrahend - this->digi[i];
    }
    for(int i=SizeMax-1;i>=0;--i){
        if(!carry)break;
        temp = this->digi[i] + carry;
        this->digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
}

std::string BigInt::ToString() const{
    bool leading = true;
    std::string num = "", tmp;
    for(int i=0;i<SizeMax;++i){
        if(!this->digi[i] && leading)continue;
        tmp = std::to_string(this->digi[i]);
        if(!leading)tmp.insert(0, BaseLen - tmp.length(), '0');
        num += tmp;
        if(this->digi[i])leading = false;
    }
    if(leading)num = "0";
    return num;
}

const BigInt operator+(const BigInt& lhs, const BigInt& rhs){
    BigInt ltmp = lhs, rtmp = rhs;
    if(ltmp.sign)ltmp.Complete();
    if(rtmp.sign)rtmp.Complete();
    uint64_t carry = 0,temp;
    //加到ltmp，並假設不會溢位
    for(int i=SizeMax-1;i>=0;--i){
        temp = ltmp.digi[i] + rtmp.digi[i] + carry;
        ltmp.digi[i] = temp % BaseMax;
        carry = temp / BaseMax;
    }
    ltmp.sign = false;
    if(ltmp.digi[0]/(BaseMax/10)!=0){
        //相加結果是負數(最高為不是0，假設不會滿位)
        ltmp.Complete();
        ltmp.sign = true;
    }
    return ltmp;
}

const BigInt operator-(const BigInt& lhs, const BigInt& rhs){
    BigInt ltmp = lhs, rtmp = rhs;
    rtmp.sign = !rtmp.sign;
    return ltmp + rtmp;
}

const BigInt operator*(const BigInt& lhs, const BigInt& rhs){
    BigInt result("0");
    uint64_t tmp;
    for(int i=SizeMax-1;i>=0;--i){
        //i for rhs j for lhs
        if(rhs.digi[i] == 0)continue;
        for(int j=SizeMax-1;j>=0;--j){
            if(lhs.digi[j] == 0)
                continue;
            tmp = lhs.digi[j] * rhs.digi[i];
            for(int k=0;tmp;++k){
                tmp = result.digi[i-(SizeMax-j)+1-k] + tmp;
                result.digi[i-(SizeMax-j)+1-k] = tmp % BaseMax;
                tmp /= BaseMax;
            }
        }
    }
    result.sign = lhs.sign ^ rhs.sign;
    return result;
}
