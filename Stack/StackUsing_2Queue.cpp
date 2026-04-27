#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class stack{
    queue<T> q1;
    queue<T> q2;

public:

    void push(T data){

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }

    void pop(){
        q1.pop();
    }

    T front(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }

};

int main(){

    stack<int> s;

    for(int i=0;i<5;i++){
        s.push(i);
    }

    while(!s.empty()){
        cout << s.front() << "-->";
        s.pop();
    }
    cout << "End" << endl;

    return 0;
}