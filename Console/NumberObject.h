#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>
#include <valarray>
#include <cctype>

typedef uint64_t BaseNum;

const BaseNum BaseMax = 100000000, subtrahend = BaseMax-1, BaseLen =8,SqrtPrecise = 100;

class Integer;
class Decimal;
class Complex;
class Ultimate;

class NumberObject{
    // root class
public:
    friend std::ostream& operator<<(std::ostream&, const NumberObject&);
    
    // Todo:在子類別實作
    virtual void Output(std::ostream&) const = 0;
    virtual std::string ToString() const = 0;
};
