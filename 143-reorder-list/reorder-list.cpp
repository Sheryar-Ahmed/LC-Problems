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
        // find middle and reverse from the middle->next;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        ListNode* prev = nullptr;
        ListNode* rev_curr = mid;
        while (rev_curr) {
            ListNode* next = rev_curr->next;
            rev_curr->next = prev;
            prev = rev_curr;
            rev_curr = next;
        }
        slow->next = nullptr; // breakdown
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            // store current's next
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};