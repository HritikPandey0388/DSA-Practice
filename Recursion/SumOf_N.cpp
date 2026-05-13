#include<iostream>
using namespace std;

int sum(int n){

    // base case
    if(n==1){
        return 1;
    }
 
    // sum of 1 to n = n + sum of 1 to n-1
    return n + sum(n-1);
}

int main(){
    
    int ans = sum(5);
    cout << ans << endl;

    return 0;
}