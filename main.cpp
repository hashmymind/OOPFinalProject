#include "calc.h"
using namespace std;

int main(){
    
    NumberObject *a, *b,*c;
    a = new Integer("1");
    b = new Decimal("2.0");
    cout << a->ToString() << endl;
}

