#pragma once
#include <map>
#include "NumberObject.h"
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"
#include "Ultimate.h"

using namespace std;

struct var{
    int type;// 0 NumberObject 1 Integer 2 Decimal 3 Complex 4 Ultimate
    Ultimate data;
};

extern map<string, var> vars;
extern map<char, int> operators;
const int inf = 0xC8763;

void init();
var getVal(string);
var operating(var, var, char);
var calc(string);
void convert(var&, int);
string dealNegativeSign(string);
string dealPowerCMD(string);
string dealFormula(string);
string ToString(var);
