#include<iostream>
using namespace std;

int Power(int a, int b){

    if(b==0){
        return 1;
    }

    int ans = Power(a,b/2);

    if(b%2!=0){
        return a*ans*ans;
    }

    return ans*ans;
}

int main(){
    
    int ans = Power(2,7);
    cout << ans << endl;

    return 0;
}