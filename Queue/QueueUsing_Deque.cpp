#include<iostream>
#include<deque>
using namespace std;

template<typename T>
class Queue{
    deque<T> deq;

public:

    // push element --> rear
    void push(T data){
        deq.push_back(data);
    }

    // delete element --> front
    void pop(){
        deq.pop_front();
    }

    // front element
    T front(){
        return deq.front();
    }

    // empty
    bool empty(){
        return deq.empty();
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