#include<iostream>
using namespace std;

void FastExponentation(int base, int pow){                   
 
    int ans = 1;

    while(pow>0){

        int lastDig = pow & 1;
        if(lastDig){
            ans *= base;
        }

        base *= base;
        pow = pow >> 1;
    }

    cout << ans << endl;

}

int main(){

    FastExponentation(3,5);

    return 0;
}