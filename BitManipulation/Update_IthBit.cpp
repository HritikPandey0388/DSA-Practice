#include<iostream>
using namespace std;

void Update_ithBit(int Num, int i, int val){                  

    // ~(1 << i) flips it all 1s except i-th bit
    Num = Num & ~(1 << i);                                       
    
    // (val << i) shifts val to i-th position
    Num = Num | (val << i);

    cout << Num << endl;
}

int main(){

    Update_ithBit(7,2,0);
    Update_ithBit(7,3,1);

    return 0;
}