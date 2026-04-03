#include<iostream>
using namespace std;

void AllPermutations(string str, string &ans, int n){

    if(ans.size()==n){
        cout << ans << endl;
        return;
    }

    for(int i=0;i<str.size();i++){

        ans.push_back(str[i]);             // including in ans 
        char ch = str[i];                  // storing for insert in backtracking step 
        str.erase(i,1);                    // removing the character taken in ans

        AllPermutations(str,ans,n);        // calling for next character

        str.insert(i,1,ch);                // inserting the ch to make original string 
        ans.pop_back();                    // excluding from ans
        
    }

}

int main(){

    string str = "abc";
    int n = str.size();
    string ans = "";

    AllPermutations(str,ans,n);

    return 0;
}