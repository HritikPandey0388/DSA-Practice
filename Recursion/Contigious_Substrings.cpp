#include<iostream>
using namespace std;

void AllSubstrings(string &str, int st, int end){

    // Size of the string
    int n = str.size();

    // Base Case:
    if(st == n){
        return;
    }

    // move to the next starting index
    if(end == n){

        // Start new substring --> start+1
        AllSubstrings(str, st + 1, st + 1);

        return;
    }

    // Print current substring
    cout << str.substr(st, end - st + 1) << endl;

    // expand substring --> increase ending index 
    AllSubstrings(str, st, end + 1);

}

int main(){

    string str = "abcab";
    string ans = "";
    AllSubstrings(str,0,0);

    return 0;
}