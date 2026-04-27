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

void PrintLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node* Reverse(Node* head){
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr!=NULL){

        next = curr->next;                   // storing address of next Node of curr
        curr->next = prev;                   // reversing curr node 

        prev = curr;                         // updating prev 
        curr = next;                         // updating curr

    }

    return prev;                             //  new Head
}

Node* SplitAtMid(Node* head){

    Node* slow = head;                       
    Node* fast = head;
    Node* prev = NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev= slow;                             // stroing prev address of slow
        slow = slow->next;                      // updating slow to +1
        fast = fast->next->next;                // updating slow to +2
    }

    if(prev!=NULL){
        prev->next = NULL;            // splitting at middle
    }

    return slow;                      // returning rightHead (slow = rightHead)

}

 Node* ZigZag(Node* head){

    Node* rightHead = SplitAtMid(head);          // finding head of the middle of LL
    Node* rightHeadrev = Reverse(rightHead);     // reversing right of the LL (we can now access LL from backward)
    
    Node* left = head;
    Node* right = rightHeadrev;
    Node* tail = right;

    while(left!=NULL && right!=NULL){

        Node* leftNext = left->next;
        Node* rightNext = right->next;

        left->next = right;
        right->next = leftNext;

        tail = right;

        left = leftNext;
        right = rightNext;

    }

    if(right!=NULL){
        tail->next = right;
    }        

}


int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // LL before ZigZag
    PrintLL(ll.head);

    // LL after ZigZag
    ZigZag(ll.head);
    PrintLL(ll.head);

    return 0;
}