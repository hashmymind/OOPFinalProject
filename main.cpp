#include "Calc.h"

int main(){
    init();
    string cmd, formula, name, type;
    while(cin >> cmd){
        if(cmd == "calc"){
            cin >> formula;
            outputVar(calc(formula));
        }else if(cmd == "set"){
            var tmp;
            cin >> type >> name >> formula >> formula;//把=弄掉
            tmp = calc(formula);
            if(type == "Integer"){
                convert(tmp, 1);
            }else if(type == "Decimal"){
                convert(tmp, 2);
            }else{
                convert(tmp, 3);
            }
            vars[name] = tmp;
            cout << name << " = ";
            outputVar(vars[name]);
        }
    }
}
