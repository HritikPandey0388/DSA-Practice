#include<iostream>
using namespace std;

int CatalanNum(int n){

    // base case
    if(n==0 || n==1){
        return 1;
    }

    int ans = 0;

    // calculating nth catalan numbers
    for(int i=0; i<n; i++){
        ans += CatalanNum(i) * CatalanNum(n-i-1);
    }

    return ans;

}

int main(){

    int n = 4;
    cout << CatalanNum(n) << endl;

    return 0;
}
