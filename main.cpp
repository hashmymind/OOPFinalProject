#include <sstream>
#include <ctime>
#include <fstream>
#include "Calc.h"
clock_t t;
map<string, var> vars;
map<char, int> operators;

string helpInfo =
"\
Setting a variable\n\
    Set Type NAME = Formula\n\
Modify a variable\n\
    Mod NAME = Formula\n\
Calculate a formula\n\
    Calc Formula\n\
Print a variable\n\
    Print NAME\n\
\n\
Note. User Should follow the format above strictly.\n",
typeWarn =
"Warning: The outcome type is not what you demand.\n",
redefine =
"Warning: Redefining a variable.\n";

void startTime(){
    t = clock();
}

double stopTime(){
    clock_t t2 = clock();
    return (double)(t2-t)/CLOCKS_PER_SEC;
}

int main(){
    init();
    cout << "If you don't know how to use, use the 'Help' command.\n";
    cout << "> ";
    string cmd, ignore;
    string type, name, formula;
    double runTime;int typeCode;
    var tmp;
    map<string, var>::iterator iter;
    while(cin >> cmd){
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        startTime();
        if(cmd == "help"){
            cout << helpInfo;
        }
        else if(cmd == "set"){
            cin >> type >> name >> ignore;
            getline(cin, formula);
            iter = vars.find(name);
            typeCode = type == "Integer"?1:(type == "Decimal"?2:(type == "Complex"?3:0));
            if(typeCode == 0){
                cout << "Error: Wrong Type!\n";
            }
            else{
                tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
                vars[name] = tmp;
                if(tmp.type != typeCode) cout << typeWarn;
                if(iter != vars.end()) cout << redefine;
            }
        }
        else if(cmd == "mod"){
            cin >> name >> ignore;
            getline(cin, formula);
            typeCode = vars[name].type;
            tmp = calc(dealNegativeSign(dealPowerCMD(formula)));
            vars[name] = tmp;
            if(tmp.type != typeCode) cout << typeWarn;
        }
        else if(cmd == "print"){
            getline(cin, formula);
            cout << *(calc(dealNegativeSign(dealPowerCMD(formula))).data) << endl;
        }
        else if(cmd == "exit"){
            exit(0);
        }
        else{
            cout << "Error: Not a command." << endl;
        }
        runTime = stopTime();
        cout << "> ";
    }
}

