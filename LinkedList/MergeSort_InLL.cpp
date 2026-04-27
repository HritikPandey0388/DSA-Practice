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

Node* Merge(Node* leftHead, Node* rightHead){

    List ans;              // ans list for storing sorted list

    Node* left = leftHead;
    Node* right = rightHead;

    while(left!=NULL && right!=NULL){
        
        if(left->data<=right->data){                // left element <= right
            ans.push_back(left->data);              // pushing in ans
            left = left->next;
        }
        else{
            ans.push_back(right->data);              // left element > right
            right = right->next;                     // pushing in ans
        }
    }

    while(left!=NULL){                     // checking if all elements in left are pushed or not
        ans.push_back(left->data);       
        left = left->next;
    }

    while(right!=NULL){                    // checking if all elements in right are pushed or not   
        ans.push_back(right->data);
        right = right->next;
    }
    
    return ans.head;                       // returning new head (newHead = head of LL ans)   

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

 Node* MergeSort(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* rightHead = SplitAtMid(head);         // finding head of the middle of LL  

    Node* left = MergeSort(head);               // calling mergeSort for left  
    Node* right = MergeSort(rightHead);         // calling mergeSort for right

    return Merge(left,right);                    // merging left and right LL

}


int main(){
    List ll;
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    // LL before MergeSort
    PrintLL(ll.head);

    // LL after MergeSort
    ll.head = MergeSort(ll.head);
    PrintLL(ll.head);

    return 0;
}