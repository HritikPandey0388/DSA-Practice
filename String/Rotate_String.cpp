#include<iostream>
#include<string>
using namespace std;


bool rotateString(string s, string goal) {

    int n = s.size();
    int i = 0; 
    while(i<n){

        if(s==goal){
            return true;
        }
            
        char ch = s[0];
        s.erase(0, 1);
        s.push_back(ch);
        i++;
    }

    return false;
        
}

int main() {

    string s1 = "abcde";
    string goal1 = "abced";

    string s2 = "abcde";
    string goal2 = "cdeab";

    cout << rotateString(s1, goal1) << endl;
    cout << rotateString(s2, goal2) << endl;

    
    return 0;
}