#include <iostream>
#include <ctime>
#include "calc.h"
using namespace std;

int main(){
    BigInt i("99999999999999999940000000000000"), j("2"),k;
    clock_t start, finish;
    start = clock();
    k = i-j;
    finish = clock();
    cout << 1000*(double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << k.ToString()<<endl;
    return 0;
}
