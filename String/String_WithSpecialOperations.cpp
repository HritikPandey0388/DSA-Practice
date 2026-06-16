#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to process the string
string processStr(string s) {

    string ans = "";

    // Traverse each character of the string
    for (char &ch : s) {

        // ch = 'a-z' --> append it
        if (ch >= 'a' && ch <= 'z') {
            ans += ch;
        }

        // ch = '*' --> remove last character
        else if (ch == '*' && !ans.empty()) {
            ans.pop_back();
        }

        // ch = '#' --> duplicate current string
        else if (ch == '#') {
            ans += ans;
        }

        // ch = '%' --> reverse the string
        else {
            reverse(ans.begin(), ans.end());
        }
    }

    return ans;
}

int main() {

    
    string s = "a#b%*";
   
    cout << processStr(s) << endl;

    return 0;
}