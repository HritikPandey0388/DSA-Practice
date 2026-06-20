#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Default constructor
    ListNode() {
        val = 0;
        next = NULL;
    }

    // Constructor with value
    ListNode(int x) {
        val = x;
        next = NULL;
    }

    // Constructor with value and next pointer
    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

ListNode* deleteDuplicates(ListNode* head) {

    // Empty list or single node
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* prev = NULL;
    ListNode* t1 = head;

    while(t1 != NULL && t1->next != NULL){

        // No duplicate
        if(t1->val != t1->next->val){
            prev = t1;
            t1 = t1->next;
        }

        else{

            // Move to first different value
            ListNode* t2 = t1->next;

            while(t2 != NULL && t2->val == t1->val){
                t2 = t2->next;
            }

            // Remove all duplicates
            if(prev == NULL){
                head = t2;
            }
            else{
                prev->next = t2;
            }

            t1 = t2;

            // List became empty
            if(head == NULL){
                return head;
            }
        }
    }

    return head;
}

void printList(ListNode* head){

    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}