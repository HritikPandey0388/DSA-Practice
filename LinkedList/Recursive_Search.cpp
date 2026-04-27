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

    int helper(Node* temp, int key){

        if(temp->data==key){
            return 0;
        }

        int idx = helper(temp->next,key);

        return idx+1;
        
    }

    int  Search(int val){
        return helper(head,val);
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

    int ans = ll.Search(3);

    ll.PrintLL();

    cout << ans << endl;

    return 0;
}