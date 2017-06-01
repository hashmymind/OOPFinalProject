#include "Formula.h"
void init(){
    Integer::LoadPrime();
    
    operators['+'] = 1;
    operators['-'] = 1;
    operators['*'] = 2;
    operators['/'] = 2;
    operators['!'] = 4;
    operators['^'] = 5;// to make Power(2,2)! right
    
    // print usage
}

var getVal(string val){
    var result;
    //
    bool dot = false, imag = false, factorial = false;
    // clean
    for(int i=0;i<val.length();++i){
        if(val[i] == ' ' || val[i] == ')' || val[i] =='('){
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
    // clean
    for(int i=0;i<val.length();++i){
        if(val[i] == 'i'){
            imag = true;
        }
        else if(val[i] == '.'){
            dot = true;
        }
        else if(!isdigit(val[i])){
            if(val[i] == '!')factorial = true;
            val.erase(val.begin() + i);
            --i;
        }
    }
    if(factorial){
        Integer n(val);
        n = Integer::Factorial(n);
        result.type = 1;
        result.data = Ultimate::Ult(n);
    }
    else if(imag){
        result.type = 3;
        result.data = Ultimate::Ult(Complex(val));
    }else if(dot){
        result.type = 2;
        result.data = Ultimate::Ult(Decimal(val));
    }else{
        result.type = 1;
        result.data = Ultimate::Ult(Integer(val));
    }
    return result;
}

var operating(var lhs, var rhs, char op){
    var result;
    result.type = max(lhs.type,rhs.type);
    
    
    if(op == '+'){
        result.data = lhs.data + rhs.data;
    }
    else if(op=='-'){
        result.data = lhs.data - rhs.data;
    }
    else if(op=='*'){
        result.data = lhs.data * rhs.data;
    }
    else if(op=='/'){
        result.data = lhs.data / rhs.data;
    }
    else{
        if(Decimal::Dec(rhs.data) == Decimal("0.5")){
            result.type = 4;
            result.data = Ultimate(Decimal::Dec(lhs.data));
        }else{
            result.data = lhs.data;
            result.type = lhs.type;
            if(result.type <= 2){
                result.data = Ultimate::Ult(Decimal::Dec(result.data).Power(Integer::Int(rhs.data)));
            }
            else if(result.type == 3){
                result.data = Ultimate::Ult(Complex::Com(result.data).Power(Integer::Int(rhs.data)));
            }
            else{
                result.data = result.data.Power(Integer::Int(rhs.data));
            }
            
        }
    }
    return result;
}


var calc(string formula){
    int baseVal = 0, opCount = 0, minLoc = -1, minVal = inf;
    map<char, int>::iterator iter;
    for(int i=0;i<formula.length();++i){
        if(formula[i] == '('){
            baseVal += 6;
        }else if(formula[i] == ')'){
            baseVal -= 6;
        }else{
            iter = operators.find(formula[i]);
            if(iter != operators.end()){
                ++opCount;
                if(iter->second + baseVal <= minVal){
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
            formula = lhs.data.ToString() + "!";
            return getVal(formula);
        }
        return result;
    }
}

string dealMutipoNegative(string formula){
    size_t finder = formula.find("--");
    while(finder!=string::npos){
        if(finder == 0 || operators.find(formula[finder-1]) != operators.end() || formula[finder-1] == '('){
            formula.erase(finder,2);
        }else{
            formula.insert(finder, "+");
            formula.erase(finder+1,2);
        }
        finder = formula.find("--");
    }
    return formula;
}

string dealNegativeSign(string formula){
    for(int i=0;i<formula.size();++i){
        if(formula[i] == '-' && (i == 0 || operators.find(formula[i-1]) != operators.end() || formula[i-1] == '(')){
            // 負號
            int rightLoc = (int)formula.size();
			int baseVal = 0;
            for(int j=i+1;j<formula.size(); ++j){
                if(baseVal == 0 && (formula[j] == ')' || operators.find(formula[j]) != operators.end())){
                    rightLoc = j;
                    break;
                }
				if (formula[j] == '(')baseVal += 1;
				if (formula[j] == ')')baseVal -= 1;
            }
            string subFormula = formula.substr(i+1, rightLoc-i-1);
            formula.erase(i,subFormula.length()+1);
            subFormula = "(0-"+subFormula+")";
            formula.insert(i,subFormula);
            i = i+2;
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

string dealFormula(string formula){
    formula = dealNegativeSign(dealMutipoNegative((dealPowerCMD(formula))));
    //trim all space
    formula.erase (std::remove (formula.begin(), formula.end(), ' '), formula.end());
    return formula;
}

bool JudgeVar(const string& name) {
	bool IsRight = false;
	string check = name;
	size_t iter;
	transform(check.begin(), check.end(), check.begin(), ::tolower);
	for (int i = 0; i < 8; ++i) {
		if (check == KeepWord[i]) {
			break;
		}
	}
	if (name == "i" || (name[0] <= '9' && name[0] >= '0')) {
		return false;
	}
	for (int i = 0; i < name.size(); i++) {
		if ((name[i] <= '9'&&name[i] >= '0') || (name[i] >= 'a'&&name[i] <= 'z') || (name[i] >= 'A'&&name[i] <= 'z')) {
			IsRight = true;
		}
		else {
			IsRight = false;
			break;
		}
	}
	return IsRight;
}