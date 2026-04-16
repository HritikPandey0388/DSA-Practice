#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string &str){

    stack<char> s;

    for(int i = 0; i < str.size(); i++){

        char ch = str[i];

        // Pushing everything except closing bracket
        if(ch != ')'){
            s.push(ch);
        }
        else{
            // stack should not be empty
            if(s.empty()){
                return false;
            } 

            // If immediate '(' → duplicate
            if(s.top() == '('){
                return true;
            }
            else{
                // Pop until '('
                while(!s.empty() && s.top() != '('){
                    s.pop();
                }

                // Remove the matching '('
                if(!s.empty()){
                    s.pop();
            
                }    
            }
        }
    }

    return false;
}

int main(){

    string str1 = "(a+b)";
    string str2 = "((a+b))";

    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;


    return 0;
}