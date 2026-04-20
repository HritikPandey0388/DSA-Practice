#include<iostream>
using namespace std;

void EvenOdd(int n){

    if(!(n & 1)){                                   // last bit = 1 (Odd number)
        cout << "given number is Even." << endl;
    }
    else{                                           // last bit = 0 (even number)
        cout << "given number is Odd." << endl;
    }

}

int main(){

    EvenOdd(4);
    EvenOdd(9);

    return 0;
}