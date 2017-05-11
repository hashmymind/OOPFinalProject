#include <map>
#include "NumberObject.h"
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

using namespace std;

struct var{
    int type;// 0 NumberObject 1 Integer 2 Decimal 3 Complex
    NumberObject * data;
};

map<string, var> vars;
map<char, int> operators;
const int inf = 0xC8763;

void init();
var getVal(string);
template<typename T1,typename T2,typename T3> void counting(const var&, const var&, var&, char);
var operating(const var&, const var&, char);
var calc(string);
void convert(var&, int);
string dealNegtiveSign(string);
void setVariable(string name, int type, string formula);
