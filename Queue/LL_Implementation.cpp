#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{

public:
    
    Node* head;
    Node* tail;
    
    Queue(){
        head = tail = NULL;
    }

    void enqueue(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void dequeue(){
        if(Empty()){
            cout << "Queue is Empty !" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    int front(){
        if(Empty()){
            cout << " Queue is Empty !" << endl;
            return -1;
        }
        return head->data;
    }

    bool Empty(){
        return head==NULL;
    }
    
};

void Print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    Print(q.head);

    return 0;
}