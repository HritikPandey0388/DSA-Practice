#include<iostream>
using namespace std;

void CountSetBits(int num){      
    
    int count = 0;
 
    while(num>0){
         
        int LastDig = num & 1;     // getting last digit 
        count += LastDig;          // adding current digit count to ans      

        num = num >> 1;            // reducing number (num = num/2)

    }

    cout << count << endl;
}

int main(){

    CountSetBits(15);

    return 0;
}