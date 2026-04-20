#include<iostream>
using namespace std;

void ClearLast_ithBit(int Num, int i){                    
 
    Num = Num & (~(0) << i);   // Clearing last i bits

    cout << Num << endl;     
}

int main(){

    ClearLast_ithBit(15,2);

    return 0;
}