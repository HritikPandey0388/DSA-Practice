#include<iostream>
using namespace std;

void AllSubstrings(string &str, int st, int end){

    int n = str.size();

    if(st==n){
        return ;
    }

    if(end==n){
        AllSubstrings(str,st+1,st+1);
        return;
    }

    cout << str.substr(st,end-st+1) << endl;

    AllSubstrings(str,st,end+1);

}

int main(){

    string str = "abcab";
    string ans = "";
    AllSubstrings(str,0,0);

    return 0;
}