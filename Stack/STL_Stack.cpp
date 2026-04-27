#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Deleting element :- ";
    int deletedEle = s.top();
    cout << deletedEle << endl;
    s.pop();

    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;

    return 0;
}