#include<iostream>
using namespace std;

int fibonacci(int n){

    // base case
    if(n==0 || n==1){
        return n;
    }

    // fibonacci of nth term -- > sum of last 2 terms (n-1 + n-2)
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    
    int ans = fibonacci(5);
    cout << ans << endl;

    return 0;
}