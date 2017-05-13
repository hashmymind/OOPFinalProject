#include "Formula.h"
void init(){
    operators['+'] = 1;
    operators['-'] = 1;
    operators['*'] = 2;
    operators['/'] = 2;
    operators['!'] = 4;
    operators['^'] = 5;// to make Power(2,2)! right
}

var getVal(string val){
    var result;
    //
    bool dot = false, imag = false, factorial = false;
    // clean
    for(int i=0;i<val.length();++i){
        if(val[i] == 'i'){
            imag = true;
        }
        else if(val[i] == '.'){
            dot = true;
        }
        else if(!isdigit(val[i]) && !isalpha(val[i])){
            if(val[i] == '!')factorial = true;
            val.erase(val.begin() + i);
            --i;
        }
    }
    //
    map<string, var>::iterator iter;
    iter = vars.find(val);//find by name
    if(iter != vars.end()){
        return iter->second;
    }
    //
    if(factorial){
        Integer n(val);
        n = Integer::Factorial(n);
        result.type = 1;
        result.data = new Integer();
        *(Integer *)result.data = n;
    }
    else if(imag){
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
    if(op == '^'){
        *(T1 *)result.data = ((*(T1 *)lhs.data).Power(*(Integer *)rhs.data));
    }
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
        }else{
            lhs = calc(formula.substr(0,minLoc));
            formula = lhs.data->ToString() + "!";
            return getVal(formula);
        }
        return result;
    }
}

void convert(var& num, int type){
    if(num.type == type)return;
    if(num.type == 1 && type == 2){
        num.type = 2;
        Decimal tmp = Decimal::IntToDecimal(*(Integer *)num.data);
        num.data = new Decimal();
        *(Decimal *)num.data = tmp;
    }else if(num.type == 1 && type == 3){
        num.type = 3;
        Complex tmp = Complex::IntToComplex(*(Integer *)num.data);
        num.data = new Complex();
        *(Complex *)num.data = tmp;
    }else if(num.type == 2 && type == 3){
        num.type = 3;
        Complex tmp = Complex::DecimalToComplex(*(Decimal *)num.data);
        num.data = new Complex();
        *(Complex *)num.data = tmp;
    }
}
string dealNegativeSign(string formula){
    for(int i=0;i<formula.size();++i){
        if(formula[i] == '-' && (i == 0 || operators.find(formula[i-1]) != operators.end() || formula[i-1] == '(')){
            // 負號
            int rightLoc = (int)formula.size()-1;
            for(int j=i+1;j<formula.size(); ++j){
                if(formula[j] == ')' || operators.find(formula[j]) != operators.end()){
                    rightLoc = j;
                    break;
                }
            }
            string subFormula = formula.substr(i+1, rightLoc-i-1);
            formula.erase(i,subFormula.length()+1);
            subFormula = "(0-"+subFormula+")";
            formula.insert(i,subFormula);
            i = i+(int)subFormula.length();
        }
    }
    return formula;
}

string dealPowerCMD(string formula){
    size_t powerLoc = formula.find("Power"), commaLoc;
    while(powerLoc != string::npos){
        commaLoc = formula.find(',', powerLoc);
        //replace comma
        formula[commaLoc] = '^';
        //insert ()
        formula.insert(commaLoc, ")");
        formula.insert(commaLoc+2, "(");
        formula.erase(powerLoc, 5);
        powerLoc = formula.find("Power");
    }
    return formula;
}


void setVariable(string name, int type, string formula){
    
}
