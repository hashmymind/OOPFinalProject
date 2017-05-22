#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>

typedef uint64_t BaseNum;

const BaseNum BaseMax = 100000000, subtrahend = BaseMax-1;
const uint32_t SizeMax = 1000, BaseLen = 8, ContainLenMax = SizeMax * BaseLen, SqrtPrecise = 10;

class Integer;
class Decimal;
class Complex;

class NumberObject{
    // root class
public:
    friend std::ostream& operator<<(std::ostream&, const NumberObject&);
    friend std::ostream& operator>>(std::ostream&, const NumberObject&);
    
    // Todo:在子類別實作
    virtual void Output(std::ostream&) const = 0;
    virtual void Input(std::istream&) = 0;
    virtual std::string ToString() const = 0;
};
