#include<iostream>
using namespace std;

void Update_ithBit(int Num, int i, int val){                    //updating Ith Bit with given value
 
    Num = Num & ~(1 << i);                                       //clear Ith Bit
    Num = Num | (val << i);

    cout << Num << endl ;

}

int main(){

    Update_ithBit(7,2,0);
    Update_ithBit(7,3,1);

    return 0;
}