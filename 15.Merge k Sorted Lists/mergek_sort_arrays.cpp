#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    // Comparator for the Min-Heap
    class ListNodeComparator {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap comparison
        }
    };

    // Function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap using a custom comparator
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> minHeap;

        // Step 1: Insert the head of each list into the min-heap
        for (auto list : lists) {
            if (list != NULL) {
                minHeap.push(list);
            }
        }

        // Step 2: Create a dummy node to simplify the code for the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Step 3: Extract the smallest node from the heap and add it to the result list
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top(); // Get the smallest node
            minHeap.pop();

            current->next = node; // Attach the node to the result list
            current = current->next;

            if (node->next != NULL) { // If the node has a next element, add it to the heap
                minHeap.push(node->next);
            }
        }

        // Step 4: Return the merged sorted list
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
    ListNode* createListFromInput() {
        int n;
        cin >> n;  // Read the number of nodes in this list

        if (n == 0) {
            return NULL;
        }

        int val;
        cin >> val;
        ListNode* head = new ListNode(val);  // Create the head node
        ListNode* current = head;

        for (int i = 1; i < n; i++) {
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        return head;
    }

    // Main function to take input and merge k sorted lists
    void run() {
        int k;
        cin >> k; // Read the number of linked lists

        vector<ListNode*> lists(k);

        // Taking runtime input for each list
        for (int i = 0; i < k; i++) {
            lists[i] = createListFromInput();
        }

        // Merge k sorted linked lists
        ListNode* mergedList = mergeKLists(lists);

        // Print the merged list
        printList(mergedList);
    }
};

int main() {
    Solution solution;
    solution.run();
    return 0;
}
