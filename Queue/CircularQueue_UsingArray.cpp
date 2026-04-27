#include<iostream>
using namespace std;

class Queue{

    int* arr;
    int currSize;
    int capacity;
    int f,r;

public:

    Queue(int capacity){
        this->capacity = capacity; 
        currSize = 0;
        f = r = -1;
        arr = new int(capacity);
    }   

    void enqueue(int val){
        if(currSize==capacity){
            cout << "Queue is Full!" << endl;
            return;
        }
        if(f==-1){
            f = 0;
        }
        r = (r+1)%capacity;
        arr[r] = val;
        currSize++;
    }

    void dequeu(){
        if(empty()){
            cout << "Queue is Empty!" << endl;
            return;
        }
        f = (f+1)%capacity;
        currSize--;
    }

    int front(){
        if(empty()){
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize==0;
    }

    void Print(){
        while(!empty()){
            cout << front() << "-->";
            dequeu();
        }
        cout << "End." << endl;
    }

};



int main(){
    Queue q(4);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.Print();

    return 0;
}