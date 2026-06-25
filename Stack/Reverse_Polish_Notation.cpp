#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {

    stack<int> s;  

    for (int i = 0; i < tokens.size(); i++) {
        // current token
        string ch = tokens[i];  

        // token --> operator
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {

            int num2 = s.top();  // Second operand
            s.pop();

            int num1 = s.top();  // First operand
            s.pop();

            // Perform the operation
            if (ch == "+")
                s.push(num1 + num2);
            else if (ch == "-")
                s.push(num1 - num2);
            else if (ch == "*")
                s.push(num1 * num2);
            else
                s.push(num1 / num2);
        }
        // token --> number
        else {
            // number string to integer and push
            s.push(stoi(ch));
        }
    }

    return s.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    cout << evalRPN(tokens);

    return 0;
}