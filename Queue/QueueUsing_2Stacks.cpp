#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class Queue{
    stack<T> s1;
    stack<T> s2;

public:

    void push(T data){

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }

    void pop(){
        s1.pop();
    }

    T front(){
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }

};

int main(){

    Queue<int> q;

    for(int i=0;i<5;i++){
        q.push(i);
    }

    while(!q.empty()){
        cout << q.front() << "-->";
        q.pop();
    }
    cout << "End" << endl;

    return 0;
}