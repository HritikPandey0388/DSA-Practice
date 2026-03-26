#include<iostream>
using namespace std;

void EvenOdd(int n){

    if(!(n & 1)){
        cout << "given number is Even." << endl;
    }
    else{
        cout << "given number is Odd." << endl;
    }

}

int main(){

    EvenOdd(4);
    EvenOdd(9);

    return 0;
}