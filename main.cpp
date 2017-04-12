#include "calc.h"
using namespace std;

int main(){
    vector<NumberObject*> nums;
    Integer i("1");
    Decimal d("0.1");
    Complex c("-1");
    nums.push_back(&i);
    nums.push_back(&d);
    nums.push_back(&c);
    
    cout << nums[2]->ToString() << endl;
    
    return 0;
}
