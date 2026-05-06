#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class stack{
    queue<T> q1;
    queue<T> q2;

public:

    // push
    void push(T data){

        // push all elements from q1 --> q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // push given data
        q1.push(data);

        // push all elements from q2 --> q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }

    // pop
    void pop(){
        q1.pop();
    }

    // top
    T front(){
        return q1.front();
    }

    // Empty
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