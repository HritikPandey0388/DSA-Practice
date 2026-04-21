#include<iostream>
using namespace std;

void IsPower(int n){

    if(!(n & (n-1))){                 // all bits after & becomes 0 --> power of 2
        cout << "True" << endl;
    }
    else{                             // atleast 1 Bit has 1 --> not power of 2
        cout << "False" << endl;
    }

}

int main(){

    IsPower(10);
    IsPower(16);

    return 0;
}