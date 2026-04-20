#include<iostream>
using namespace std;

int Clear_ithBit(int n, int i){

    int BitMask = ~(1 << i);  // mask with 0 at i-th position

    return (n & BitMask);     // clearing i-th bit
}
int main(){

    cout << Clear_ithBit(6,1) << endl;

    return 0;
}