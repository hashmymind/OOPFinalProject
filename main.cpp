#include <sstream>
#include "Calc.h"
map<string, var> vars;
map<char, int> operators;
int main(){
    init();
    string raw;
    cout << "> ";
    while(getline(cin, raw)){
        string cmd, formula, name, type;
        stringstream ssin(raw);
        map<string, var>::iterator iter;
        ssin >> cmd;
        iter = vars.find(cmd);
        if(cmd == "set"){
            var tmp;
            ssin >> type >> name >> formula;//把=弄掉
            ssin.ignore();
            getline(ssin, formula);
            tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
            if(type == "Integer"){
                convert(tmp, 1);
            }else if(type == "Decimal"){
                convert(tmp, 2);
            }else{
                convert(tmp, 3);
            }
            vars[name] = tmp;
            cout << name << " = ";
            cout << *vars[name].data << endl;
        }else if(cmd == "debug"){
            ssin.ignore();
            getline(ssin, formula);
            cout << dealNegativeSign(dealPowerCMD(formula)) << endl;
            
        }
        else if(cmd == "mod"){
            
        }else if(iter != vars.end()){
            var tmp;
            ssin >> formula;
            name = cmd;
            if(formula != ""){
                //assign
                ssin.ignore();
                getline(ssin, formula);
                tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
                vars[name] = tmp;
            }
            cout << name << " = " << *vars[name].data << endl;
        }else{
            formula = raw;
            cout << *calc(dealNegativeSign(dealPowerCMD(formula))).data << endl;
        }
        cout << "> ";
    }
}
