#include<iostream>
using namespace std;

void ClearLast_ithBit(int Num, int i){                    
 
    Num = Num & (~(0) << i);

    cout << Num << endl;

}

int main(){

    ClearLast_ithBit(15,2);

    return 0;
}