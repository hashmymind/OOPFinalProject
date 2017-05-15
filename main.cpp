#include <sstream>
#include <ctime>
#include "Calc.h"
clock_t t;
map<string, var> vars;
map<char, int> operators;

void startTime(){
    t = clock();
}

void stopTime(){
    clock_t t2 = clock();
    cout << (double)(t2-t)/CLOCKS_PER_SEC << "s" << endl;
}

int main(){
    init();
    string raw;
    cout << "> ";
    while(getline(cin, raw)){
        startTime();
        string cmd, formula, name, type;
        stringstream ssin(raw);
        map<string, var>::iterator iter;
        ssin >> cmd;
        iter = vars.find(cmd);
        if(cmd == "Set"){
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
        }else if(cmd == "Debug"){
            ssin.ignore();
            getline(ssin, formula);
            cout << dealNegativeSign(dealPowerCMD(formula)) << endl;
            
        }
        else if(cmd == "Mod"){
            
        }else if(iter != vars.end()){
            var tmp;
            ssin >> formula;
            name = cmd;
            if(formula == "="){
                //assign
                ssin.ignore();
                getline(ssin, formula);
                tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
                vars[name] = tmp;
                cout << name << " = " << *vars[name].data << endl;
            }else{
                //calc
                cmd = formula;
                getline(ssin, formula);
                formula = name + cmd + formula;
                tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
                cout << *tmp.data << endl;
            }
            
        }else{
            formula = raw;
            cout << *calc(dealNegativeSign(dealPowerCMD(formula))).data << endl;
        }
        stopTime();
        cout << "> ";
    }
}

