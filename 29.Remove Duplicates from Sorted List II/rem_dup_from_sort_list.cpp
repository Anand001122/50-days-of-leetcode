#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *current = head, *prev = NULL;
    
    while (current != NULL) {
        int val = current->val;
        if (current->next != NULL && current->next->val == val) {
            while (current != NULL && current->val == val) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            if (prev == NULL) {
                head = current;
            } else {
                prev->next = current;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Empty list" << endl;
        return 0;
    }
    
    cout << "Enter " << n << " sorted integers: ";
    ListNode *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ListNode* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    
    head = deleteDuplicates(head);
    printList(head);
    
    // Clean up memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}