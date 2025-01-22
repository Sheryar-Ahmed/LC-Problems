class Solution {
public:
    // Helper function to check if there are at least k nodes remaining
    bool hasKNodes(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == NULL) {
                return false; // Not enough nodes
            }
            temp = temp->next;
        }
        return true;
    }

    // Helper function to reverse k nodes in the list
    ListNode* reverseKNodes(ListNode* head, int k, ListNode*& nextGroup) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;

        // Reverse k nodes
        while (curr != NULL && count < k) {
            next = curr->next;  // Save the next node
            curr->next = prev;  // Reverse the link
            prev = curr;        // Move prev forward
            curr = next;        // Move curr forward
            count++;
        }
        nextGroup = curr; // The starting node for the next group
        return prev;      // Return the new head of the reversed group
    }

    // Main function
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are enough nodes to reverse
        if (!hasKNodes(head, k)) {
            return head; // Not enough nodes, return as is
        }

        // Step 2: Reverse the first k nodes
        ListNode* nextGroup = NULL;
        ListNode* newHead = reverseKNodes(head, k, nextGroup);

        // Step 3: Recursively reverse the remaining nodes and connect
        head->next = reverseKGroup(nextGroup, k);

        // Step 4: Return the new head of the reversed group
        return newHead;
    }
};
