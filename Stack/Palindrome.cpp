#include<iostream>
#include<stack>
#include<list>
using namespace std;

bool isPalindrome(list<int> &l){

    // Always Palindrome
    if(l.size()==0 || l.size()==1){
        return true;
    }

    stack<int> s;
    auto itr = l.begin();

    // pushing all element of list in stack
    while(itr!=l.end()){
        s.push(*itr);
        ++itr;
    }

    itr = l.begin();

    // traversing each element from the beginning in given list
    while(itr!=l.end()){
        
        // Not a Palindrome
        if(*itr != s.top()){
            return false;
        }

        // checcking for next element
        ++itr;
        s.pop();
    }

    return true;
}

int main(){

    list<int> l1 = {1};
    list<int> l2 = {1,2,3,4,3,2};

    cout << isPalindrome(l1) << endl;
    cout << isPalindrome(l2) << endl; 

    return 0;
}