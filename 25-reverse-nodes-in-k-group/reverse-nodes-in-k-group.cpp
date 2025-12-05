class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        
        // Step 1: ensure k nodes exist
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // fewer than k nodes
            curr = curr->next;
        }

        // Step 2: reverse k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: recursively process the rest
        head->next = reverseKGroup(curr, k);

        // Step 4: prev is the new head of this reversed block
        return prev;
    }
};
