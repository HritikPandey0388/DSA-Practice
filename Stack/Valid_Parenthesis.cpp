#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string &str){

    stack<char> s;

    for(int i=0;i<str.size();i++){

        // current character
        char ch = str[i];

        // ch --> opening bracket (push to stack)
        if(ch=='(' || ch=='[' || ch=='{'){
            s.push(ch);
        }
        // ch --> closing bracket
        else{
            
            // stack --> Empty (not valid)
            if(s.empty()){
                return false;
            }
            
            // stck top should match ch
            char top = s.top();
            if( (top=='(' && ch==')') || 
                    (top=='[' && ch==']') || 
                    (top=='{' && ch=='}') ){
                s.pop();
            }
            // if doesn't match --> not valid
            else{
                return false;
            }

        }
    }

    // stack should be empty 
    return s.empty();

}

int main(){

    string str = "(()})}";

    bool ans = isValid(str);

    if(ans==1){
        cout << "Valid" << endl;
    }
    else{
        cout << "Not Valid" << endl;
    }

    return 0;
}