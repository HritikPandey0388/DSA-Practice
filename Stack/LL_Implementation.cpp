#include<iostream>
#include<list>
using namespace std;

template<class T>
class Node{
public:    
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }    
};

template<class T>
class Stack{
    Node<T>* head;

public:

    Stack(){
        head = NULL;
    }

    // push()
    void push(T val){
        Node<T>* newNode = new Node<T>(val);
        if(head==NULL){
            head = newNode;           
        }
        else{
            newNode->next = head;        // pushing newNode before current Head   
            head = newNode;              // updating head
        }
        
        return;

    }

    // pop()
    void pop(){
        
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;          // updating head 
        delete temp;                // deleting prev head memory
        temp = NULL;                // dangling pointer
    }
    
    // top()
    T top(){
        return head->data;
    }

    // empty()
    bool isEmpty(){
        return head==NULL;
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