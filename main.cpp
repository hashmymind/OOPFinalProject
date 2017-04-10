#include "calc.h"
using namespace std;

int main(){
    Decimal d("1");
    Integer e("1");
    vector<NumberObject*> nums;
    nums.push_back(&d);
    nums.push_back(&e);
    for(const auto& num : nums){
        cout << *num << endl;
    }
    
    /*clock_t start, finish;
     start = clock();
    
    finish = clock();
    cout << 1000*(double)(finish - start) / CLOCKS_PER_SEC << " ms" << endl;*/
    return 0;
}
