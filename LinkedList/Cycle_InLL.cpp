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
public:
    Node *head;
    Node *tail;
    
    List(){
        head=tail=NULL;
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



};

bool isCycle(Node* head){

    Node* slow = head;                          // starting slow and fast from head
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;                      // moving slow to +1 position
        fast = fast->next->next;                // moving fast to +2 position  

        if(slow==fast){                         // base conition
            cout << "Cycle exits." << endl;
            return true;
        }
    }

    cout << "Cycle doesn't exist." << endl;
    return false;

}

int main(){
    List ll;
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    ll.tail->next = ll.head;

    isCycle(ll.head);

    return 0;
}