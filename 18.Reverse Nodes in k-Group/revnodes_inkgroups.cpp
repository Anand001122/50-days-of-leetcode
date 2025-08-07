#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a portion of the linked list
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;
        
        // Reverse the first k nodes
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // Return the new head of the reversed section
        return prev;
    }

    // Function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* current = head;

        // Iterate over the linked list
        while (current != NULL) {
            ListNode* groupStart = current;
            int count = 0;
            
            // Check if there are k nodes remaining in the list
            while (current != NULL && count < k) {
                current = current->next;
                count++;
            }
            
            // If there are k nodes, reverse them
            if (count == k) {
                ListNode* groupEnd = groupStart;
                for (int i = 1; i < k; i++) {
                    groupEnd = groupEnd->next;
                }
                
                ListNode* nextGroupStart = groupEnd->next;
                groupEnd->next = NULL;

                // Reverse the k nodes
                ListNode* newGroupStart = reverseLinkedList(groupStart, k);
                
                // Connect the previous group's end to the new reversed group
                prevGroupEnd->next = newGroupStart;
                groupStart->next = nextGroupStart;
                
                // Move the prevGroupEnd pointer to the end of the current reversed group
                prevGroupEnd = groupStart;
                
                // Set the current pointer to the start of the next group
                current = nextGroupStart;
            } else {
                break;
            }
        }

        return dummy->next;
    }

    // Helper function to print the linked list
    void printList(ListNode* head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Helper function to create a linked list from user input
    ListNode* createListFromInput(int n) {
        if (n == 0) return NULL;

        int val;
        cin >> val;
        ListNode* head = new ListNode(val);
        ListNode* current = head;

        for (int i = 1; i < n; i++) {
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        return head;
    }
};

int main() {
    Solution solution;

    // Take input for the linked list
    int n, k;
    cin >> n;

    // Create the linked list from input
    ListNode* head = solution.createListFromInput(n);

    // Take input for k
    cin >> k;

    // Reverse nodes in k-group
    ListNode* newHead = solution.reverseKGroup(head, k);

    // Print the modified list
    solution.printList(newHead);

    return 0;
}
