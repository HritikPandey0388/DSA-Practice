#include<iostream>
using namespace std;

int Set_ithBit(int n, int i){

    int BitMask = 1 << i;      // create i 0's with leading 1

    return (n | BitMask);      // | operation makes 0-->1, 1-->1

}

int main(){

    cout << Set_ithBit(6,3) << endl;

    return 0;
}