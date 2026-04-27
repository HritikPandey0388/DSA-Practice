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

void RemoveCycle(Node* head){

    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast!=NULL && fast->next!=NULL){
        
        slow = slow->next;
        fast = fast->next->next;
        

        if(slow==fast){
            cout << "Cycle exits." << endl;
            isCycle = true;
            break;
        }

    }

    if(!isCycle){
        cout << "Cycle doesn't exist." << endl;
        return;
    }

    slow = head;

    if(slow==fast){
        while(fast->next!=slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else{
        Node* prev = fast;
        while(slow!=fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
    }

}

int main(){
    List ll;
    ll.push_back(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    ll.tail->next = ll.head;
    // 0->1->2->3->4->0

    RemoveCycle(ll.head);
    // 0->1->2->3->4->NULL

    return 0;
}