#include<iostream>
using namespace std;

void ClearBits(int Num, int i, int j){                    
 
    int left = (1 << (j+1));                   // making left Bits 
    int right = ~(~(0) << i);                  // making right Bits 

    int BitMask = (left | right);              //desired bitmask 

    Num = (Num & BitMask);

    cout << Num << endl;

}

int main(){

    ClearBits(31,2,3);

    return 0;
}