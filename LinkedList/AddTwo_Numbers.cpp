#include <iostream>
using namespace std;

// Defining singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to add 2 LinkedList
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);
    int carry = 0;
    ListNode* head = l3;

    while (l1 && l2) {
        int value = l1->val + l2->val + carry;
        carry = value / 10;
        l3->next = new ListNode(value % 10);

        l1 = l1->next;
        l2 = l2->next;
        l3 = l3->next;
    }

    while (l1) {
        int value = l1->val + carry;
        carry = value / 10;
        l3->next = new ListNode(value % 10);

        l1 = l1->next;
        l3 = l3->next;
    }

    while (l2) {
        int value = l2->val + carry;
        carry = value / 10;
        l3->next = new ListNode(value % 10);

        l2 = l2->next;
        l3 = l3->next;
    }

    if (carry) {
        l3->next = new ListNode(carry);
    }

    return head->next;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Helper to create list from array
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