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
        if (!head || !head->next)
            return;
        // find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // now my slow pointer is at the middle
        ListNode* prev = NULL;
        ListNode* curr = slow->next; // reverse from the slow upto the end;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // now my curr is successfully reversed
        slow->next = nullptr; // now our head is just first half;
        // merge
        ListNode* first = head;
        ListNode* second = prev; // prev our reversed half
        while (second) {
            // get the both next
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            // first->next will be the second element
            first->next = second;
            // second->next will be the first->next
            second->next = temp1;
            // shift the frist and second
            first = temp1;
            second = temp2;
        }
    }
};