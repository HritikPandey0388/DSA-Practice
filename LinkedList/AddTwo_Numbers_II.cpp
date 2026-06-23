#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
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

// Store linked list values in vector
void helper(ListNode* head, vector<int>& nums) {
    while (head != NULL) {
        nums.push_back(head->val);
        head = head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // store LinkedLists
    vector<int> nums1;
    vector<int> nums2;

    helper(l1, nums1);
    helper(l2, nums2);

    int i = nums1.size() - 1;
    int j = nums2.size() - 1;

    int carry = 0;
    ListNode* head = NULL;

    while (i >= 0 || j >= 0 || carry) {

        // calculate sum
        int sum = carry;

        if (i >= 0) {
            sum += nums1[i];
            i--;
        }

        if (j >= 0) {
            sum += nums2[j];
            j--;
        }

        // calculate carry
        carry = sum / 10;

        // update LinkedList
        ListNode* newNode = new ListNode(sum % 10);
        newNode->next = head;
        head = newNode;
    }

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

    // l1 = 7 -> 2 -> 4 -> 3
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    // l2 = 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* ans = addTwoNumbers(l1, l2);

    cout << "LinkedList 1 :- ";
    printList(l1); 

    cout << "LinkedList 2 :- ";
    printList(l2);  

    cout << "Ans -: ";
    printList(ans);

    return 0;
}