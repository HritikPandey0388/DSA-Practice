#include<iostream>
#include<stack>
using namespace std;

string Reverse(string str){

    stack<char> s;
    string ans;

    // including each character of string
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }

    // with help of stack we will get string in reverse order
    while(!s.empty()){
        char ch = s.top();
        ans += ch;
        s.pop();
    }

    return ans;

}

int main(){

    string str = "abcd";

    string ans = Reverse(str);

    cout << ans << endl;
    
    return 0;
}