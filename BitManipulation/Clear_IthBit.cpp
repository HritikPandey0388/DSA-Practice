#include<iostream>
using namespace std;

int Clear_ithBit(int n, int i){

    int BitMask = ~(1 << i);

    return (n & BitMask);

}

int main(){

    cout << Clear_ithBit(6,1) << endl;

    return 0;
}