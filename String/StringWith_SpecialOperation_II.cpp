#include <iostream>
#include <string>
using namespace std;

char processStr(string s, long long k) {

    long long len = 0;

    // find length of string after all operatons
    for (char ch : s) {

        // ch = 'a-z'
        if (ch >= 'a' && ch <= 'z') {
            len++;
        }

        // ch = '*' --> removes last character 
        else if (ch == '*') {
            if (len > 0) {
                len--;
            }
        }

        // ch = '#' --> duplicate current string 
        else if (ch == '#') {
            len *= 2;
        }

        // ch = '%' --> reverse string
        else if(ch == '%'){
            continue;
        }
    }

    // k --> out of bound
    if (k >= len) {
        return '.';
    }

    // discard each character from reverse
    for (int i = s.size() - 1; i >= 0; i--) {

        char ch = s[i];

        // ch = '*' --> length chnages
        if (ch == '*') {
            len++;
        }

        // ch = '%' --> k changes
        else if (ch == '%') {
            k = len - k - 1;
        }

        // ch = '#' --> length and k both changes
        else if (ch == '#') {
            len = len / 2;

            if (k >= len) {
                k -= len;
            }
        }

        // ch = 'a-z' --> length changes
        else {
            len--;
        }

        // ch --> required character
        if (k == len) {
            return s[i];
        }
    }

    return '.';
}

int main() {

    string s = "a#b%*";
    long long k = 1;

    cout << processStr(s, k) << endl;

    return 0;
}