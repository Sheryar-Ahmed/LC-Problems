/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Copy the list into a vector for easy access
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        // Step 2: Reverse the entire linked list
        ListNode* prev = nullptr;
        curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // now prev is the head of reversed list

        // Step 3: Merge original order and reversed order
        int n = nodes.size();
        ListNode* p1 = head;
        ListNode* p2 = prev;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int i = 0; i < n / 2; i++) {
            tail->next = nodes[i];   // original node
            tail = tail->next;

            tail->next = nodes[n - 1 - i]; // reversed node
            tail = tail->next;
        }

        if (n % 2 == 1) {
            tail->next = nodes[n / 2];
            tail = tail->next;
        }

        tail->next = nullptr;
    }
};
