#include<iostream>
using namespace std;

class Queue{

    int* arr;          
    int currSize;      
    int capacity;      
    int f, r;          

public:

    // initialize queue
    Queue(int capacity){

        this->capacity = capacity; 
        currSize = 0;

        // queue --> empty
        f = r = -1;

        // Allocate memory for queue array
        arr = new int[capacity];
    }   

    // Insert element
    void enqueue(int val){

        // Queue --> full
        if(currSize == capacity){
            cout << "Queue is Full!" << endl;
            return;
        }

        // If first element inserted
        if(f == -1){
            f = 0;
        }

        // Circular increment of rear
        r = (r + 1) % capacity;

        // Insert element at rear
        arr[r] = val;

        // Increase current size
        currSize++;
    }

    // Remove element
    void dequeu(){

        // queue --> empty
        if(empty()){
            cout << "Queue is Empty!" << endl;
            return;
        }

        // Move front forward circularly
        f = (f + 1) % capacity;

        // Decrease size
        currSize--;
    }

    // front element
    int front(){

        // Queue --> empty
        if(empty()){
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return arr[f];
    }

    // Empty
    bool empty(){
        return currSize == 0;
    }

    // Accessing all elements
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