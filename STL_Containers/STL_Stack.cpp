#include<iostream>
#include<stack>
using namespace std;

int main(){

    // Initializing by STL
    stack<int> s;

    // push
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Deleting element :- ";
    int deletedEle = s.top();
    cout << deletedEle << endl;
    s.pop();

    // accessing each element
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;

    return 0;
}