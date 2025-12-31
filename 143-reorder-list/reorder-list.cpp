class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split and reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Merge two halves
        ListNode* start = head;
        while (prev) {
            ListNode* temp1 = start->next;
            ListNode* temp2 = prev->next;

            start->next = prev;
            prev->next = temp1;

            start = temp1;
            prev = temp2;
        }
    }
};
