#include <iostream>
#include <ctime>
#include "calc.h"
using namespace std;

int main(){
    Decimal d("1") , e("3");
    //
    clock_t start, finish;
    start = clock();
    d = d / e;
    string s = d.ToString();
    cout << s.length() << endl;
    cout << s << endl;
    finish = clock();
    cout << 1000*(double)(finish - start) / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
