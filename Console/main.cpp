#include <sstream>
#include <ctime>
#include <fstream>
#include "Calc.h"
clock_t t;
map<string, var> vars;
map<char, int> operators;

ofstream outputsRecord("outputs.txt");

string helpInfo =
"\
Setting a variable\n\
    Set Type NAME = Formula\n\
Modify a variable\n\
    Mod NAME = Formula\n\
Print a Formula\n\
    Print Formula\n\
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

bool outputTime = false;

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
                tmp = calc(dealFormula(formula));
                if(tmp.type != typeCode){
                    if(typeCode == 1){
                        tmp.data = Ultimate::Ult(Integer::Int(tmp.data));
                    }
                    else if(typeCode == 2){
                        tmp.data = Ultimate::Ult(Decimal::Dec(tmp.data));
                    }
                    else if(typeCode == 3){
                        tmp.data = Ultimate::Ult(Complex::Com(tmp.data));
                    }
                    tmp.type = typeCode;
                }
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
            if(tmp.type != typeCode){
                if(typeCode == 1){
                    tmp.data = Ultimate::Ult(Integer::Int(tmp.data));
                }
                else if(typeCode == 2){
                    tmp.data = Ultimate::Ult(Decimal::Dec(tmp.data));
                }
                else if(typeCode == 3){
                    tmp.data = Ultimate::Ult(Complex::Com(tmp.data));
                }
                tmp.type = typeCode;
            }
            vars[name] = tmp;
            if(tmp.type != typeCode) cout << typeWarn;
        }
        else if(cmd == "print"){
            getline(cin, formula);
            string ans = calc(dealFormula(formula)).data.ToString();
            cout << ans << endl;
            outputsRecord << ans << "\n-------------------------\n";
        }
        /*else if(cmd == "calc"){
            getline(cin, formula);
            cout << calc(dealFormula(formula)).data << endl;
        }*/
        else if(cmd == "exit"){
            outputsRecord.close();
            exit(0);
        }
        else if(cmd == "debug"){
            Integer i;Decimal d = "123.3"; Complex c = "123+123i";
            i = "123+1";
            cout << i << endl;
        }
        else{
            cout << "Error: Not a command." << endl;
        }
        runTime = stopTime();
        if(outputTime) cout << runTime << endl;
        cout << "> ";
    }
}

