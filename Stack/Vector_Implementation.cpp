#include<iostream>
#include<vector>
using namespace std;

template<class T>

class Stack{
    vector<T> vec;
public:

   // push()
    void push(T val){
        vec.push_back(val);
    }

    // pop()
    void pop(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return;
        }
        vec.pop_back();
    }

    // top()
    T top(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return -1;
        }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    // empty()
    bool isEmpty(){
        return vec.size()==0;
    }

};

int main(){

    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Top :- " ;
    while(!s.isEmpty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;

    return 0;

}