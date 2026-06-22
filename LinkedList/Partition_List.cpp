#include <iostream>
using namespace std;

// Linked List Node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* partition(ListNode* head, int x) {

    // Empty list or single node
    if (!head || !head->next) {
        return head;
    }

    ListNode* lessHead = new ListNode(0);
    ListNode* greaterHead = new ListNode(0);

    ListNode* less = lessHead;
    ListNode* greater = greaterHead;

    ListNode* curr = head;

    // Partition the list
    while (curr != nullptr) {

        if (curr->val < x) {
            less->next = curr;
            less = less->next;
        }
        else {
            greater->next = curr;
            greater = greater->next;
        }

        curr = curr->next;
    }

    // End greater list
    greater->next = nullptr;

    // Connect both lists
    less->next = greaterHead->next;

    ListNode* newHead = lessHead->next;

    delete lessHead;
    delete greaterHead;

    return newHead;
}

// Print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // linked list: 1->4->3->2->5->2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Before Partition :- ";
    printList(head);

    head = partition(head, x);

    // Print result
    ListNode* temp = head;


    head = partition(head, x);

    cout << "After Partitioned :- ";
    printList(head);

    return 0;
}