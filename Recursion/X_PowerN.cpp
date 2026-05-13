#include<iostream>
using namespace std;

int Power(int a, int b){

    // base case:
    if(b==0){
        return 1;
    }

    // recursively calculate a^(b/2)
    int ans = Power(a,b/2);

    // exponent --> odd:
    if(b%2!=0){
        return a*ans*ans;
    }

    // exponent --> even
    return ans*ans;
}
int main(){
    
    int ans = Power(2,7);
    cout << ans << endl;

    return 0;
}