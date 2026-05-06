#include<iostream>
#include<deque>
using namespace std;

template<typename T>
class Stack{
    deque<T> deq;

public:

    // push
    void push(T data){
        deq.push_front(data);
    }

    // pop
    void pop(){
        deq.pop_front();
    }

    // Top
    T front(){
        return deq.front();
    }

    // Empty
    bool empty(){
        return deq.empty();
    }

};

int main(){

    Stack<int> s;

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