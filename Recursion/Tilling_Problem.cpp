#include<iostream>
using namespace std;

int helper(int n){          // (2 x n) size Tiles  using (2 x 1)
    
    if(n==0 || n==1){
        return 1;
    }

    // when tile placed vertical
    int ans1 = helper(n-1);

    // when tile is placed horizontal
    int ans2 = helper(n-2);;

    return ans1+ans2;
}

int main(){
    
    int n = 5;

    int ans = helper(n);
    cout << ans << endl;

    return 0;
}