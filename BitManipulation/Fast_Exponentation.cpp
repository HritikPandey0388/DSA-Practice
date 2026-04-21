#include<iostream>
using namespace std;

void FastExponentation(int base, int pow){

    int ans = 1;  

    while(pow > 0){

        // lastBit --> 0/1
        int lastDig = pow & 1;

        // If 1 --> multiply current base with answer
        if(lastDig){
            ans *= base;
        }

        // Square the base for next iteration
        base *= base;

        // updating power (divide by 2)
        pow = pow >> 1;
    }

    cout << ans << endl;
}

int main(){

    FastExponentation(3,5);   // 3^5 = 243

    return 0;
}