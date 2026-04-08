#include<iostream>
using namespace std;

class Node{
public:

    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class List{
    
    Node *head;
    Node *tail;

public:
    
    List(){
        head=tail=NULL;
    }

    void push_front(int val){

        Node* newNode = new Node(val);
        
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }

        return;

    }

    void push_back(int val){

        Node* newNode = new Node(val);
        
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

        return;
        
    }

    void pop_back(){
        
        if(head==NULL){
            cout << "LL is empty" << endl;
            return;
        }
        
        Node*  temp=head;
        while(temp->next!=tail){
            temp = temp->next; 
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;

        return;
        
    }

    void pop_front(){

        if(head==NULL){
            cout << "LL is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        return;
        
    }

    // function for getting size of a LL
    int getSize(){                         
        Node* temp = head;
        int size = 0;

        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        return size;

    }

    // deleting Nth node from last
    void deleteNode(int n){

        if(n==1){
            pop_back();
            return;
        }

        int size = getSize();

        if(n==size){
            
            pop_front();
            return;
        }

        Node* prev = head;                   // declaring prev so that address previous of Nth node can be accessed 

        for(int i=0;i<(size-n);i++){
            prev = prev->next;
        }

        Node* ToDel = prev->next;
        cout << "Going to delete " << ToDel->data << endl; 
        prev->next = prev->next->next;
        delete ToDel;                                 // deleting Nth node from last
        ToDel = NULL;

    }

    void PrintLL(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "-->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

};

int main(){
    List ll;
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    cout << "LinkedList before deletion :-" << endl;
    ll.PrintLL();

    ll.deleteNode(2);
    cout << "LinkedList after deletion :-" << endl;
    ll.PrintLL();

    return 0;
}