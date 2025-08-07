#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            // Perform the swap
            prev->next = b;
            a->next = b->next;
            b->next = a;

            // Move prev to the next pair
            prev = a;
        }

        return dummy.next;
    }
};

// Helper: Convert a vector to a linked list
ListNode* listToLinkedList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy.next;
}

// Helper: Convert a linked list to a vector
vector<int> linkedListToList(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Helper: Parse space-separated integers into a vector
vector<int> parseInputLine(const string& line) {
    vector<int> result;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        result.push_back(number);
    }
    return result;
}

int main() {
    string inputLine;
    getline(cin, inputLine);

    vector<int> nums = parseInputLine(inputLine);
    ListNode* head = listToLinkedList(nums);

    Solution solution;
    ListNode* newHead = solution.swapPairs(head);

    vector<int> output = linkedListToList(newHead);
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i + 1 < output.size()) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}