class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head; // If the list is empty, return

        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move the fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (!fast) return head; // If n is greater than the length of the list
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        delete toDelete; // Free memory for the removed node
        return dummy->next; // Return the updated list
    }
};
