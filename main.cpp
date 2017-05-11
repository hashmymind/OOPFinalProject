#include "Calc.h"
map<string, var> vars;
map<char, int> operators;
int main(){
    init();
    
    string cmd, formula, name, type;
    while(cin >> cmd){
        if(cmd == "calc"){
            cin >> formula;
            cout << *calc(formula).data << endl;
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
            cout << *vars[name].data << endl;
        }
    }
}
