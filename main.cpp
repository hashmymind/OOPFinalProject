#include <iostream>
#include <ctime>
#include "calc.h"
using namespace std;

int main(){
    BigInt i("10"), j("500"),k;
    clock_t start, finish;
    start = clock();
    k = i*j;
    finish = clock();
    cout << "乘法 " << 1000*(double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
    cout << k.ToString()<<endl;
    return 0;
}
