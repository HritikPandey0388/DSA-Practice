#include<iostream>
#include<string>
using namespace std;

int LCS(string s1, string s2){

    int n = s1.size();
    int m = s2.size();

    // base case
    if(n == 0 || m == 0){
        return 0;
    }

    // char --> same include char ,call for substring
    if(s1[n-1] == s2[m-1]){
        return 1 + LCS(s1.substr(0, n-1), s2.substr(0, m-1));
    }

    else{
        int ans1 = LCS(s1.substr(0, n-1), s2);           // ignore last char from s1
        int ans2 = LCS(s1, s2.substr(0, m-1));           // ignore last char from s2
        return max(ans1, ans2);                          // maximum of both
    }
}

int main(){

    string s1 = "abcdge";
    string s2 = "abedg";

    cout << LCS(s1, s2) << endl;

    return 0;
}