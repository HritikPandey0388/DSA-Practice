#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // Dummy node for result linked list
    ListNode* l3 = new ListNode(0);

    // Carry generated during addition
    int carry = 0;

    // store head for new LL
    ListNode* head = l3;

    // Traverse both linked lists together
    while (l1 && l2) {

        // Add current digits + previous carry
        int value = l1->val + l2->val + carry;

        // Update carry
        carry = value / 10;

        // Store current digit in result list
        l3->next = new ListNode(value % 10);

        // Move all pointers forward
        l1 = l1->next;
        l2 = l2->next;
        l3 = l3->next;
    }

    // If elements remain in l1
    while (l1) {

        // Add remaining digit with carry
        int value = l1->val + carry;

        // Update carry
        carry = value / 10;

        // Store current digit
        l3->next = new ListNode(value % 10);

        // Move forward
        l1 = l1->next;
        l3 = l3->next;
    }

    // If elements remain in l2
    while (l2) {

        // Add remaining digit with carry
        int value = l2->val + carry;

        // Update carry
        carry = value / 10;

        // Store current digit
        l3->next = new ListNode(value % 10);

        // Move forward
        l2 = l2->next;
        l3 = l3->next;
    }

    // If carry still remains
    if (carry) {
        l3->next = new ListNode(carry);
    }

    // Return actual head
    return head->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// create list from array
ListNode* createList(int arr[], int n) {

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};        // 3-->4-->2-->NULL
    int arr2[] = {5, 6, 4};        // 4-->6-->5-->NULL

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2);   // 7 -> 0 -> 8 -> NULL

    printList(result); 

    return 0;
}