#include <iostream>
#include <ctime>
#include "calc.h"
using namespace std;

int main(){
    Decimal d("0.2");
    clock_t start, finish;
    start = clock();
    d.Reduce();
    finish = clock();
    cout << 1000000*(double)(finish - start) / CLOCKS_PER_SEC << " us" << endl;
    return 0;
}
