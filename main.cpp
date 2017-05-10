#include "calc.h"
#include <map>
using namespace std;

struct var{
    int type;// 0 NumberObject 1 Integer 2 Decimal 3 Complex
    NumberObject * data;
};

map<string, var> vars;
map<char, int> operators;

const int inf = 0xC8763;

void init(){
    operators['+'] = 1;
    operators['-'] = 1;
    operators['*'] = 2;
    operators['/'] = 2;
    operators['^'] = 3;
    operators['!'] = 3;
}

var getVal(string val){
    var result;
    //
    // try varList
    //
    bool dot = false, imag = false;
    // clean
    for(int i=0;i<val.length();++i){
        if(val[i] == 'i'){
            imag = true;
        }
        else if(val[i] == '.'){
            dot = true;
        }
        else if(!isdigit(val[i])){
            val.erase(val.begin() + i);
            --i;
        }
    }
    //
    if(imag){
        result.type = 3;
        result.data = new Complex(val);
    }else if(dot){
        result.type = 2;
        result.data = new Decimal(val);
    }else{
        result.type = 1;
        result.data = new Integer(val);
    }
    return result;
}

template<typename T1,typename T2,typename T3>
void counting(const var& lhs, const var& rhs, var& result, char op){
    if(op == '+')
        *(T3 *)result.data = *(T1 *)lhs.data + *(T2 *)rhs.data;
    if(op == '-')
        *(T3 *)result.data = *(T1 *)lhs.data - *(T2 *)rhs.data;
    if(op == '*')
        *(T3 *)result.data = *(T1 *)lhs.data * *(T2 *)rhs.data;
    if(op == '/')
        *(T3 *)result.data = *(T1 *)lhs.data / *(T2 *)rhs.data;
}

var operating(const var& lhs, const var& rhs, char op){
    var result;
    
    result.type = max(lhs.type, rhs.type);
    if(result.type == 1){
        result.data = new Integer();
        counting<Integer,Integer,Integer>(lhs,rhs,result,op);
    }
    else if(result.type == 2){
        result.data = new Decimal();
        if(lhs.type != 2)
            counting<Integer,Decimal,Decimal>(lhs,rhs,result,op);
        else if(rhs.type != 2)
            counting<Decimal,Integer,Decimal>(lhs,rhs,result,op);
        else
            counting<Decimal,Decimal,Decimal>(lhs,rhs,result,op);
    }
    else{
        result.data = new Complex();
        if(lhs.type == 1)
            counting<Integer,Complex,Complex>(lhs,rhs,result,op);
        else if(lhs.type == 2)
            counting<Decimal,Complex,Complex>(lhs,rhs,result,op);
        else if(rhs.type == 1)
            counting<Complex,Integer,Complex>(lhs,rhs,result,op);
        else if(rhs.type == 2)
            counting<Complex,Decimal,Complex>(lhs,rhs,result,op);
        else
            counting<Complex,Complex,Complex>(lhs,rhs,result,op);
    }
    return result;
}


var calc(string formula){
    int baseVal = 0, opCount = 0, minLoc = -1, minVal = inf;
    map<char, int>::iterator iter;
    for(int i=0;i<formula.length();++i){
        if(formula[i] == '('){
            baseVal += 5;
        }else if(formula[i] == ')'){
            baseVal -= 5;
        }else{
            iter = operators.find(formula[i]);
            if(iter != operators.end()){
                ++opCount;
                if(iter->second + baseVal < minVal){
                    minLoc = i;
                    minVal = iter->second + baseVal;
                }
            }
        }
    }
    if(!opCount){
        return getVal(formula);
    }
    else{
        var lhs, rhs, result;
        if(formula[minLoc]!='!'){
            lhs = calc(formula.substr(0,minLoc));
            rhs = calc(formula.substr(minLoc+1, formula.length()-minLoc));
            return operating(lhs, rhs, formula[minLoc]);
        }
        return result;
    }
}

void outputVar(var num){
    if(num.type == 1){
        cout << *(Integer *)num.data << endl;
    }else if(num.type == 2){
        cout << *(Decimal *)num.data << endl;
    }
    else{
        cout << *(Complex *)num.data << endl;
    }
}

int main(){
    init();
    string cmd, formula;
    while(cin >> cmd){
        if(cmd == "calc"){
            cin >> formula;
            outputVar(calc(formula));
        }
    }
}

int setVariable(string name, int type, string formula){
    return 0;
}

