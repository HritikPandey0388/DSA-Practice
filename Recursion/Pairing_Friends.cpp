#include<iostream>
using namespace std;

int Pairing(int n){

    // Base cases:
    // 1 Person --> stays single
    // 2 Person --> both make pair or both stands single
    if(n==1 || n==2){
        return n;
    }

    // Case 1:
    // nth person stays single
    int single = Pairing(n-1);

    // Case 2:
    // nth person pairs with any one of the remaining (n-1) people
    // reamaining make pairs
    int pairUp = (n-1) * Pairing(n-2);

    // Total ways = single ways + pairing ways
    return single + pairUp;

}
int main(){

    int n = 4;

    int ans = Pairing(n);
    cout << ans << endl;

    return 0;
}