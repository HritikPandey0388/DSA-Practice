#include <iostream>
using namespace std;

// singly-linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

ListNode* temp = NULL;
int count;

// Recursive function to reverse values between left and right
void reverseList(ListNode* head, int left, int right, int count) {

    // Base case
    if (head == NULL || count > (right - left + 1)) {
        return;
    }

    // Recursive call
    reverseList(head->next, left, right, count + 1);

    // avoid duplicate swaps
    if (count <= (right - left + 1) / 2) {
        return;
    }

    // Swap values --> Backtrack
    swap(temp->val, head->val);
    temp = temp->next;
}

// Reverse nodes between left and right positions
ListNode* reverseBetween(ListNode* head, int left, int right) {

    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    temp = head;
    count = 1;

    while (count < left) {
        count++;
        temp = temp->next;
    }

    count = 1;
    reverseList(temp, left, right, count);

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before :- ";
    printList(head);

    int left = 2;
    int right = 4;

    // Reverse between positions
    head = reverseBetween(head, left, right);

    cout << "After :- ";
    printList(head);

    return 0;
}