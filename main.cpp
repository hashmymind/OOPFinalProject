#include "calc.h"
using namespace std;

int main(){
    Integer i1("4412313213465646451"), i2("7897454531231231313"), i3, i4(1,false);
    i3 = i1 * i2;
    cout << i3.ToString() << endl;
    for(int i=0;i<18;i++)i4.LeftShift();
    cout << i4.ToString()<<endl;
    return 0;
}
