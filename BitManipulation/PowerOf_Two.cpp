#include<iostream>
using namespace std;

void IsPower(int n){

    if(!(n & (n-1))){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

}

int main(){

    IsPower(10);
    IsPower(16);

    return 0;
}