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
    while(temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void OddEven(Node* &head){

    // Head and Tail pointers for Even linked list
    Node* EvenHead = NULL;
    Node* EvenTail = NULL;

    // Head and Tail pointers for Odd linked list
    Node* OddHead = NULL;
    Node* OddTail = NULL;
    
    Node* temp = head;
    while(temp != NULL){
        
        // Store next node before breaking links
        Node* next = temp->next;

        // Disconnect current node from original list
        temp->next = NULL;
        
        // If current node contains even data
        if(temp->data % 2 == 0){
            
            // First even node
            if(EvenHead == NULL){
                EvenHead = EvenTail = temp; 
            }
            // Attach node at end of even list
            else{
                EvenTail->next = temp;
                EvenTail = temp;
            }
        }
        else{
            
            // First odd node
            if(OddHead == NULL){
                OddHead = OddTail = temp;
            }
            // Attach node at end of odd list
            else{
                OddTail->next = temp;
                OddTail = temp;
            }
        }
        
        temp = next;
    }
    
    // Connect even list with odd list
    if(EvenTail != NULL){
        EvenTail->next = OddHead;
    }
    
    // Update head of final list
    if(EvenHead == NULL){
        head = OddHead;
    }
    else{
        head = EvenHead;
    }

}

int main(){

    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    cout << "Given LL :-" << endl;
    PrintLL(ll.head);

    OddEven(ll.head);

    cout << "After :- " << endl;
    PrintLL(ll.head);

    return 0;
}
