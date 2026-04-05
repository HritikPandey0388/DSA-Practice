#include<iostream>
using namespace std;

void AllSubsets(string str, string &ans, int Idx){

    int n = str.size();

    if(Idx==n){
        cout << ans << endl;              //  base case
        return;
    }

    ans.push_back(str[Idx]);              // including 
    AllSubsets(str,ans,Idx+1);            // calling for next subset

    ans.pop_back();                       // excluding
    AllSubsets(str,ans,Idx+1);            // calling for next subset

}

int main(){

    string str = "abc";
    string ans = "";

    AllSubsets(str,ans,0);

    return 0;
}