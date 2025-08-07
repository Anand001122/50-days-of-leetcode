#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to head
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
    }

    // Helper function to convert list to linked list
    ListNode* listToLinkedList(const vector<int>& lst) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for (int val : lst) {
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy->next;
    }

    // Helper function to convert linked list to list
    vector<int> linkedListToList(ListNode* node) {
        vector<int> result;
        while (node != nullptr) {
            result.push_back(node->val);
            node = node->next;
        }
        return result;
    }
};

int main() {
    // Reading input
    vector<int> inputList;
    int val;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> val) {
        inputList.push_back(val);
    }
    int n;
    cin >> n;

    // Process the input list and remove the nth node from the end
    Solution solution;
    ListNode* head = solution.listToLinkedList(inputList);
    ListNode* newHead = solution.removeNthFromEnd(head, n);

    // Output the resulting linked list as a list
    vector<int> result = solution.linkedListToList(newHead);
    
    // Printing the result
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
