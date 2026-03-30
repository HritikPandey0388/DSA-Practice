// This code is a complex one .
// we can also do it by passing ans as passing by value ans .

#include<iostream>
using namespace std;

void BinaryString(int n, string &ans){

    if(n==0){
        cout << ans << endl;
        return;
    }

    if(ans.size()>0 && ans[ans.size()-1]=='1'){

        ans.push_back('0');        // including 0
        BinaryString(n-1,ans);
        ans.pop_back();            //  excluding 0
    
    }    
    else{
    
        ans.push_back('0');        // including 0  
        BinaryString(n-1,ans);
        ans.pop_back();            //  excluding 0
        
        ans.push_back('1');        //  including 1
        BinaryString(n-1,ans);
        ans.pop_back();            //  excluding 1
    
    }
    
}

int main(){

    int n = 3;
    string ans = "";
    BinaryString(n,ans);

    return 0;
}