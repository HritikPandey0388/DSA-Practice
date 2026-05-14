#include<iostream>
using namespace std;

int fact(int n){

    // base case
    if(n==0){
        return 1;
    }

    // factorial of n = n* factorial of n-1
    return n*fact(n-1);
}

int main(){
    
    int ans = fact(5);
    cout << ans << endl;

    return 0;
}