#include<iostream>
using namespace std;

void CountSetBits(int num){      
    
    int count = 0;
 
    while(num>0){
        
        int LastDig = num & 1;
        count += LastDig;

        num = num >> 1;

    }

    cout << count << endl;
}

int main(){

    CountSetBits(15);

    return 0;
}