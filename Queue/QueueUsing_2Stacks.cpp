#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class Queue{

    stack<T> s1;   // main stack
    stack<T> s2;   // Temporary stack

public:

    // Insert element
    void push(T data){

        // Move all elements from s1 to s2
        while(!s1.empty()){

            s2.push(s1.top());
            s1.pop();
        }

        // Insert new element in s1
        s1.push(data);

        // Move all elements from s2 to s1
        while(!s2.empty()){

            s1.push(s2.top());
            s2.pop();
        }

    }

    // Remove front element
    void pop(){

        s1.pop();
    }

    // front element
    T front(){

        return s1.top();
    }

    // empty
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