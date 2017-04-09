#include <iostream>
#include <ctime>
#include "calc.h"
using namespace std;

int main(){
    Integer i(BaseMax-1,false), j("88888888888888888888888"),k;
    clock_t start, finish;
    i.LeftShift();
    start = clock();
    k = j / i;
    cout << k.ToString() << endl;
    finish = clock();
    cout << 1000*(double)(finish - start) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}
