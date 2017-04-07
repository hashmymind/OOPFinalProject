#include <iostream>
#include "calc.h"
using namespace std;

int main(){
    BigInt i("1000000000000"), j("1"),k;
    k = i + j;
    cout << k.ToString() << endl;
    return 0;
}
