#include<iostream>
#include<stack>
using namespace std;

void PushAtBottom(stack<int> &s, int val){

    if(s.empty()){
        s.push(val);           // pushing the given value at bottom
        return;
    }

    int temp = s.top();       
    s.pop();                  // exclude
    PushAtBottom(s,val);      // recursion

    s.push(temp);            // backtracking

}

void ReverseStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    ReverseStack(s);

    PushAtBottom(s,temp);

}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    ReverseStack(s);

    cout << "Top :- ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}