#include<iostream>
using namespace std;

int GridWays(int r, int c, int n, int m, string ans){

    if(r==(n-1) && c==(m-1)){               // base case
        cout << ans << endl;                // printing ans and return
        return 1;
    }

    if(c>=m || r>=n){                       // index out off scope  
        return 0;
    }

    int right = GridWays(r,c+1,n,m,ans+'R');                 // calling for right ways 
    int down = GridWays(r+1,c,n,m,ans+'D');                  // calling for down ways

    return (right + down);
}

int main(){
    
    int n = 3;
    string ans = "";

    int totalWays = GridWays(0,0,n,n,ans);
    
    cout << "Number of Ways are : " << totalWays << endl;
    
    return 0;
}