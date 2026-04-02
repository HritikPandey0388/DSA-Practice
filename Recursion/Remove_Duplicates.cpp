#include<iostream>
#include<string>
using namespace std;


void helper(string &str, int Idx, string &ans){   
    
    if(Idx==str.size()){
        return;
    }

    if(ans.find(str[Idx])==string::npos){      // checking if Idx th character already exist in ans
        ans = ans + str[Idx];
    }

    return helper(str,Idx+1,ans);
    
}

int main(){
    
    string str = "appnnacollege";
    string ans = "";

    helper(str,0,ans);

    cout << ans << endl;

    return 0;
}