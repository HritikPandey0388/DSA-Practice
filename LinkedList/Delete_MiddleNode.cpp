#include<iostream>
using namespace std;

class ListNode{
public:

    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }

};

void printLL(ListNode* head){

    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode* deleteMiddle(ListNode* head){

    // if LL has 0 or 1 node
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    // slow will stop at node before middle
    ListNode* slow = head;
    ListNode* fast = head->next->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // middle node
    ListNode* middle = slow->next;

    // remove middle node
    slow->next = middle->next;

    delete middle;

    return head;
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original LL :- ";
    printLL(head);

    head = deleteMiddle(head);

    cout << "After deleting middle :- ";
    printLL(head);

    return 0;
}