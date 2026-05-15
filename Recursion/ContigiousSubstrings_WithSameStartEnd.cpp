#include<iostream>
using namespace std;

void AllSubstrings(string &str, int st, int end){
    
    int n = str.size();

    // Base case
    if(st==n){
        return ;
    }

    // If ending index --> end,
    // move to next starting index
    if(end==n){

        // Start new substring from next position
        AllSubstrings(str,st+1,st+1);
        return;
    }

    // first character = last character
    if(str[st]==str[end]){

        // Print substring 
        cout << str.substr(st,end-st+1) << endl;
    }

    // Expand current substring --> end+1
    AllSubstrings(str,st,end+1);

}

int main(){

    string str = "abcab";
    string ans = "";
    AllSubstrings(str,0,0);

    return 0;
} 